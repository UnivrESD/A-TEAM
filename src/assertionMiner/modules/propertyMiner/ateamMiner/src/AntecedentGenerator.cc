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
    saveOffset=false;

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
    // the propositions in the current antecedent
    List<Proposition> &usedPropositions = antecedent->getItems();

    double maxRIG = 0.0;
    auto vbest    = unusedVars.end();

    DecTreeVariables toLeaf;

    // getting the relative information gain (RIG) for each unused variable X
    // RIG (Y|X) = (H(Y) - H(Y|X)) / H(Y)
    auto candidate = unusedVars.begin();
    for (; candidate != unusedVars.end() && maxRIG < 1; ++candidate) {

        // the 2 propositions of X
        Proposition **propPtr = dcVariables[*candidate];

        // conditioned entropy:   H(Y|X) = for each x in X : p(X=x) * H(Y|X=x)
        double condEnt = 0.0;

        // for each proposition that belongs to a unused variable (namely x)
        for (size_t propI = 0; propI < 2; ++propI) {

            Proposition *prop = propPtr[propI];
            if (prop == nullptr)
                continue;

            // add the new proposition of a unused variable in the current
            // antecedent
            usedPropositions.push_back(prop);
            // std::cout << "current: " << usedPropositions.size() << " -> "
            //       << oden::prop2String(*antecedent) << "\n";

            MT::Result_DC res = MT::mean_MT(antecedent, _traceInfo);

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

                if (res.occGoal == 0 || res.occGoal == res.occProposition) {
                    entropyYgivenXx = 0;
                    _store(*antecedent, res.occGoal != 0);

                    dcVariables[*candidate][propI] = nullptr;
                    toLeaf[*candidate][propI]      = prop;
                }

                // H(Y|X)
                condEnt += probXx * entropyYgivenXx;
            }

            usedPropositions.pop_back();
        }

        double RIG = (_entropyGoal - condEnt) / _entropyGoal;

        if (RIG > maxRIG) {
            maxRIG = RIG;
            vbest  = candidate;
        }
    }
    //------------------------------------------------------------------------

    //=================== make a new node of the decision tree ===============
    if (usedPropositions.size() < maxPropositions &&
        !(_traceInfo->initTrue == _traceInfo->reachedTrue ||
          vbest == unusedVars.end())) {

        size_t removedVar = *vbest;

        // remove the vbest variable from the unused variables set
        unusedVars.erase(vbest);

        Proposition **propPtr = dcVariables[removedVar];
        for (size_t i = 0; i < 2; ++i) {
            Proposition *prop = propPtr[i];
            if (prop != nullptr) {
                usedPropositions.push_back(prop);
                _runDecisionTree(unusedVars, dcVariables, antecedent);
                usedPropositions.pop_back();
            }
        }

        unusedVars.push_back(removedVar);
    }
    //------------------------------------------------------------------------

    for (auto &kv : toLeaf) {
        size_t varNum         = kv.first;
        Proposition **propPtr = kv.second;
        for (size_t propI = 0; propI < 2; ++propI)
            if (dcVariables[varNum][propI] == nullptr)
                dcVariables[varNum][propI] = propPtr[propI];
    }
}

void AntecedentGenerator::_store(PropositionAnd &antecedent, bool value) {

    if (!value && !saveOffset){
//        std::cout << "Not storing:" <<oden::prop2String(antecedent)<< "\n";
        return;
    }

    // std::cout << "store: " << oden::prop2String(antecedent) << " " << value
    //          << " " << _traceInfo->reachedTrue << "\n";

    List<PropositionAnd> shorterAntecedents;
    _simplify(antecedent, value, shorterAntecedents);

    while (!shorterAntecedents.empty()) {
        PropositionAnd *shorterAntecedent = shorterAntecedents.pop_front();
        List<Proposition> &props          = shorterAntecedent->getItems();

        if (_traceInfo->initTrue != _traceInfo->reachedTrue) {
            _getCoverage(*shorterAntecedent, value);

            // Let's save the current propositions
            set<Proposition *> newSolution;
            while (!props.empty())
                newSolution.insert(props.pop_front());

            if (value)
                onSets.insert(newSolution);
            else
                offSets.insert(newSolution);
        } else
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
                    _traceInfo->reachedTrue++;
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
