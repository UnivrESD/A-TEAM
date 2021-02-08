#include "../include/AntecedentGenerator.hh"
#include "../include/SetsGenerator.hh"
#include "oden/odenUtils/odenUtils.hh"
#include "supportMethods.hh"

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <thread>

namespace ateam {

namespace {
namespace MT /* multi-thread methods */ {

// the maximum number of threads
static const unsigned MAX_THREADS = 1;

// the current number of cpu cores
static const size_t availThreads =
    std::min(MAX_THREADS, std::thread::hardware_concurrency());

// the result of the decision-tree algorithm
struct Result_DC {
    size_t occProposition; // how many times is the proposition satisfied?
    size_t
        occGoal; // how many times are the goal and the proposition satisfied?
};

//
Result_DC mean_MT(Proposition *proposition, TraceInfo *traceInfo) {
    std::thread threadArray[MAX_THREADS];
    size_t occProposition[MAX_THREADS]{}; // how many times we satisfied the
                                          // proposition
    size_t occGoal[MAX_THREADS]{};        // how many times we hit the goal

    size_t length     = traceInfo->length;
    Proposition *goal = traceInfo->goal;

    cout << "MEAN_MT: " << oden::prop2String(*proposition) << endl;
    for (size_t nThread = 0; nThread < availThreads; ++nThread) {
        threadArray[nThread] = std::thread(
            [nThread, length, proposition, goal, &occProposition, &occGoal]() {
                for (size_t i = nThread; i < length; i += availThreads) {
                    if (!proposition->evaluate(i))
                        continue;

                    ++occProposition[nThread];

                    if (goal->evaluate(i))
                        ++occGoal[nThread];
                }
            });
    }

    // join threads
    for (size_t i = 0; i < availThreads; ++i)
        threadArray[i].join();

    Result_DC res{0, 0};
    for (size_t i = 0; i < availThreads; ++i) {
        res.occProposition += occProposition[i];
        res.occGoal += occGoal[i];
    }

    return res;
}

void verify_MT(List<Proposition> &allPropositions, TraceInfo *traceInfo,
               bool value, setsGenerator::Sets &sets, bool *result) {

    size_t traceLength = traceInfo->length;
    Proposition *goal  = traceInfo->goal;
    std::thread threadArray[MAX_THREADS];

    for (size_t nThread = 0; nThread < availThreads; ++nThread) {
        threadArray[nThread] = std::thread([nThread, &allPropositions,
                                            traceLength, value, goal, &sets,
                                            result]() {
            // making a new propositionAnd
            auto *propAnd            = new PropositionAnd();
            List<Proposition> &props = propAnd->getItems();

            for (size_t thID = nThread; thID < sets.numSets;
                 thID += availThreads) {

                // adding the atomic propositions
                for (size_t j = 0; j < sets.setSize; ++j) {
                    size_t propIndex = sets.setsArray[thID * sets.setSize + j];
                    props.push_back(allPropositions[propIndex]);
                }

                // it is never true that pros is true and goal is false
                result[thID] = true;
                for (size_t i = 0; i < traceLength && result[thID]; ++i)
                    result[thID] =
                        !(propAnd->evaluate(i) && goal->evaluate(i) != value);

                // removing the atomic propositions
                while (!props.empty())
                    props.pop_back();
            }
            delete propAnd;
        });
    }
    // join threads
    for (size_t i = 0; i < availThreads; ++i)
        threadArray[i].join();
}

} // namespace MT
} // namespace

AntecedentGenerator::AntecedentGenerator()
    : maxPropositions(0), onSets(), offSets(), _traceInfo(nullptr),
      saveOffset(true), _entropyGoal(1) {
    // ntd
}

TraceInfo &AntecedentGenerator::makeAntecedents(DecTreeVariables &dcVariables,
                                                TraceInfo &traceInfo) {
    _traceInfo = &traceInfo;

    std::list<size_t> unusedVars;
    for (size_t i = 0; i < dcVariables.size(); ++i)
        unusedVars.push_back(i);

    _entropyGoal = support::getEntropy(traceInfo.initTrue, traceInfo.length);

    // Run decision tree
    auto *antecedent = new PropositionAnd();
    _runDecisionTree(unusedVars, dcVariables, antecedent);
    delete antecedent;

    // return 1 - static_cast<double>(_goals) / static_cast<double>(initGoals);
    return traceInfo;
}

void AntecedentGenerator::_runDecisionTree(list<size_t> &unusedVars,
                                           DecTreeVariables &dcVariables,
                                           PropositionAnd *antecedent) {
    ///
    cout << "RUN DECISIONE TREE: " << endl;

    // the propositions in the current antecedent
    List<Proposition> &usedPropositions = antecedent->getItems();

    cout << "usedPropositions size: " << usedPropositions.size() << endl;
    double maxRIG = 0.0;
    auto vbest    = unusedVars.end(); //ritorna l'iteratore all'ultimo elemento della lista

    ///
    cout << "RIG: " << maxRIG <<  endl;
    cout << "unusedVars: " << endl;
    for (auto i = unusedVars.begin(); i!= unusedVars.end(); i++){
        cout << "Elemento: " <<*i << endl;
    }


    DecTreeVariables toLeaf;

    // getting the relative information gain (RIG) for each unused variable X
    // RIG (Y|X) = (H(Y) - H(Y|X)) / H(Y)
    auto candidate = unusedVars.begin(); //iteratore al primo elemento/posizione

    // itero su ogni proposizione nell'antecedente
    for (; candidate != unusedVars.end() && maxRIG < 1; ++candidate) {

        // the 2 propositions of X (esempio a e il suo negato !a)
        Proposition **propPtr = dcVariables[*candidate];

        // conditioned entropy:   H(Y|X) = for each x in X : p(X=x) * H(Y|X=x)
        double condEnt = 0.0;
        // for each proposition that belongs to a unused variable (namely x)
        for (size_t propI = 0; propI < 2; ++propI) {

            Proposition *prop = propPtr[propI];

            // può essere che sia stata scartata precedentemente nella prima 
            // chiamata dela funzione
            if (prop == nullptr)
                continue;

            ///
            cout << "Proposizioni: " << oden::prop2String(*prop) << endl; //dopo il controllo, altrimenti seg fault
            //cout << "Numero antecedenti presi: " << usedPropositions.size() << endl;
            
            // add the new proposition of a unused variable in the current
            // antecedent
            usedPropositions.push_back(prop);

            // valuto l'asserzione sulla traccia
            MT::Result_DC res = MT::mean_MT(antecedent, _traceInfo);

            ///
            // occProposition: numero di volte in cui la proposizione è vera nella traccia (AT)
            // occGoal: numero di volte in cui proposizione -> conseguente è vero nella traccia (AT CT)
            cout << "occGoal: " << res.occGoal << "    occProposition: " << res.occProposition << endl;

            // is the new antecedent at least once satisfied? (avoid vacuity)
            if (res.occProposition > 0) {
                // P(X=x)
                double probXx = static_cast<double>(res.occProposition) /
                                static_cast<double>(_traceInfo->length);
                // P(Y|X=x)
                double propYTrueGivenXx =
                    static_cast<double>(res.occGoal) /
                    static_cast<double>(res.occProposition);

                // // P(!Y|X=x)
                double propYFalseGivenXx = 1 - propYTrueGivenXx;

                // H(Y|X=x)
                double entropyYgivenXx =
                    ((-1) * propYTrueGivenXx * log2(propYTrueGivenXx) +
                     (-1) * propYFalseGivenXx * log2(propYFalseGivenXx));

                cout << "probXx= " << probXx << "   propYTrueGivenXx= " << propYTrueGivenXx << endl;
                cout << "probYFalseGivenXx= " << propYFalseGivenXx << "   EntropiaYGivenXx = " << entropyYgivenXx << endl;
                
                // res.occGoal == 0 ---> visto che occProposition > 0 , se occGoal == 0 allora ci sono 
                //                       dei casi in cui AT CF
                //                       Infatti viene passato a _store il occGoal!=0 per distinguere in quale caso siamo
                //                       se siamo nel caso di occGoal == 0 allora verrà considerato il negato del conseguente (!sum)
                // res.occGoal == res.occProposition ----> tutte le volte in cui vale il conseguente allora vale anche l'antecedente
                //                                         non ci sono casi di AT CF per cui posso costruire l'asserzione con antecedente -> conseguente
                if (res.occGoal == 0 || res.occGoal == res.occProposition) {
                    entropyYgivenXx = 0; // puro? serve per sistemare il -nan ottenuto dai logaritmi precedentemente

                    // Viene effettivamente scelto l'antecedente e onset o offset del conseguente
                    _store(*antecedent, res.occGoal != 0);
                    std::cout << "setting " << prop2String(*antecedent) << "null" << std::endl;
                    dcVariables[*candidate][propI] = nullptr;
                    toLeaf[*candidate][propI]      = prop;
                }

                // H(Y|X)
                condEnt += probXx * entropyYgivenXx;
            }
            std::cout << "antecedent size: " << antecedent->size() << std::endl;
            usedPropositions.pop_back();
            std::cout << "antecedent size: " << antecedent->size() << std::endl;
        }

        /// è qua che scelgo quello che massimizza la riduzione di entropia
        /// la formula è quasi uguale tranne che c'è un fratto in più
        double RIG = (_entropyGoal - condEnt) / _entropyGoal;
        cout << "Entropy Goal: " << _entropyGoal << "    RIG= " << RIG << endl;

        if (RIG > maxRIG) {
            maxRIG = RIG;
            vbest  = candidate;
        }
    }
    //------------------------------------------------------------------------

    //=================== make a new node of the decision tree ===============
    // usedPropositions.size() < maxPropositions ---> se non ho già scelto tutte le proposizioni
    if (usedPropositions.size() < maxPropositions &&
        !(_traceInfo->initTrue == _traceInfo->reachedTrue ||
          vbest == unusedVars.end())) {

                
        // posizione della proposizione scelta
        size_t removedVar = *vbest;

        // remove the vbest variable from the unused variables set
        // vbest è la proposizioni scelta prima con RIG maggiore tra tutte
        unusedVars.erase(vbest);

        // the 2 propositions of X
        Proposition **propPtr = dcVariables[removedVar];
        for (size_t i = 0; i < 2; ++i) {
            Proposition *prop = propPtr[i];
            // se prima avevo scartato !b perchè occGoal == 0 ad esempio
            // ora prop == !b == nullptr e quindi non viene creato il ramo
            if (prop != nullptr) {
                cout << "Proposizioni scelta, ramo: " << oden::prop2String(*prop) << endl;
                usedPropositions.push_back(prop);
                _runDecisionTree(unusedVars, dcVariables, antecedent);
                usedPropositions.pop_back();
            }
        }

        unusedVars.push_back(removedVar);
    }
    //------------------------------------------------------------------------

    // da capire? sarebbero le foglie? o in generale tutto l'albero?
    for (auto &kv : toLeaf) {
        size_t varNum         = kv.first;
        Proposition **propPtr = kv.second;
        for (size_t propI = 0; propI < 2; ++propI)
            if (dcVariables[varNum][propI] == nullptr){
                dcVariables[varNum][propI] = propPtr[propI];
                 //cout << "..... " << prop2String(*propPtr[propI]) << endl;
            }
        
    }
}

void AntecedentGenerator::_store(PropositionAnd &antecedent, bool value) {
    // In atecendet al primo giro mi trovo con a && b, poi quando esco
    // viene fatta la pop_back e viene tolto a e si ritorna in questa funzione con
    // b && !a

    if (!value && !saveOffset){
        // std::cout << "Not storing:" <<oden::prop2String(antecedent)<< "\n";
        return;
    }

     std::cout << "store: " << oden::prop2String(antecedent) << " " << value
              << " " << _traceInfo->reachedTrue << "\n";

    List<PropositionAnd> shorterAntecedents;
    _simplify(antecedent, value, shorterAntecedents);

    // in shorteAntecedents c'è l'antecedenteAnd attuale semplicficato
    // o non semplificato se non è stato possibile
    /// cout << "..........." << prop2String( *shorterAntecedents[0] )<<endl;

    while (!shorterAntecedents.empty()) {
        PropositionAnd *shorterAntecedent = shorterAntecedents.pop_front();
        List<Proposition> &props          = shorterAntecedent->getItems();

        if (_traceInfo->initTrue != _traceInfo->reachedTrue) {
            _getCoverage(*shorterAntecedent, value);

            // Let's save the current propositions
            set<Proposition *> newSolution;
            while (!props.empty())
                newSolution.insert(props.pop_front());

            // è qua che scelgo in base a value se si tratta di un sum oppure di un !sum
            if (value)
                onSets.insert(newSolution);
            else
                offSets.insert(newSolution);
        } else
            // svuota la lista
            while (!props.empty())
                props.pop_front();

        delete shorterAntecedent;
    }
}

void AntecedentGenerator::_simplify(PropositionAnd &antecedent, bool value,
                                    List<PropositionAnd> &shorterProps) {

    List<Proposition> &allPropositions = antecedent.getItems();
    size_t numPropositions             = allPropositions.size();

    //  messageInfo("-----SIMPLIFY------");
    //  messageInfo(prop2String(antecedent));
    //  messageInfo("-------------------");

    size_t setSize = 1;
    for (; setSize < numPropositions && shorterProps.empty(); ++setSize) {

        /* Viene creato un insieme di size=1 che aumenta size finchè minore del numero di proposizioni
           nell'antecedente quindi se antecedente (a && b) allora setSize sarà massimo di 1 e non di più*/

        setsGenerator::Sets sets;
        sets.setSize  = setSize;
        sets.numItems = numPropositions;

        setsGenerator::makeSubSets(sets);
        bool *result = new bool[sets.numSets];
        MT::verify_MT(allPropositions, _traceInfo, value, sets, result);

        for (size_t i = 0; i < sets.numSets; ++i) {
            if (result[i]) {
                auto *p = new PropositionAnd();
                for (size_t j = 0; j < setSize; ++j) {
                    size_t indexProp = sets.setsArray[i * setSize + j];
                    p->getItems().push_back(allPropositions[indexProp]);
                }
                shorterProps.push_back(p);
            }
        }

        delete[] result;
    }

    if (shorterProps.empty()) {
        auto *p = new PropositionAnd();
        for (size_t j = 0; j < numPropositions; ++j)
            p->getItems().push_back(allPropositions[j]);

        shorterProps.push_back(p);
    }
}

void AntecedentGenerator::_getCoverage(PropositionAnd &proposition,
                                       bool value) {
    for (size_t time = 0; time < _traceInfo->length; ++time) {
        if (proposition.evaluate(time)) {
            if (value) {
                if (_traceInfo->coverageTrue->evaluate(time)) {
                    _traceInfo->coverageTrue->assign(time, false);
                    //_traceInfo->reachedTrue++;
                }
            } else {
                if (_traceInfo->coverageFalse->evaluate(time)) {
                    _traceInfo->coverageFalse->assign(time, false);
                    _traceInfo->reachedFalse++;
                }
            }
        }
    }
}

} // namespace ateam

