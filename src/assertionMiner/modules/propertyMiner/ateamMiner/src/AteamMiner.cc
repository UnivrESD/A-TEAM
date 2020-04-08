#include "AteamMiner.hh"
#include "AntecedentGenerator.hh"
#include "oden/odenUtils/odenUtils.hh"
#include "supportMethods.hh"

#include <algorithm>
#include <iostream>
#include <list>
#include <spot/tl/print.hh>
#include <unordered_set>

// TODO: find a better place for this global variable
const char *coverageReport = "coverageReport.txt";

namespace /**/ {
void saveCoverageReport(List<Assertion> &assertions) {
    if (assertions.empty())
        return;

    std::ofstream outputFile(coverageReport);
    for (Assertion *assertion : assertions) {
        outputFile << assertion->id << ": ";
        for (size_t faultyTraceID : assertion->faultList)
            outputFile << faultyTraceID << " ";
        outputFile << "\n";
    }
    outputFile.close();
}
} // namespace

namespace ateam {

AteamMiner::AteamMiner(XmlNode *xmlNode)
    : PropertyMiner(xmlNode), _fchecker(nullptr),
      _antec2CandInProps(), _antec2CandOutProps(),
      _antec2CandInoutProps(), _templates(),
      _maxVariablesAntecedent(5), traceInfo() {

    //==== read user-defined templates
    //=========================================

    // TODO
    /*

    XmlNode *templatesXml =
    configuration->first_node("templates");
    messageErrorIf(templatesXml == nullptr,
                   "The xml tag templates has not been
    found");

    _readAssertionTemplates(templatesXml);
    */

    /*For now, we allow only a fixed template, the
    consequents can still be
    everything*/
    _readTemplate("G(p1 -> p2)");

    //--------------------------------------------------------------------------

    //==== reading constraints
    //=================================================
    XmlNode *constraints =
        configuration->first_node("constraints");
    if (constraints != nullptr) {
        string maxVariables =
            getAttributeValue(constraints, "maxVariables");
        messageErrorIf(maxVariables.empty(),
                       "The attribute maxVariables in the "
                       "xml tag constraints has "
                       "not been found");

        _maxVariablesAntecedent =
            static_cast<size_t>(std::stoi(maxVariables));
    }
    //--------------------------------------------------------------------------

    XmlNode *faultyTraces =
        configuration->first_node("faultyTraces");
    if (faultyTraces != nullptr) {
        string list =
            getAttributeValue(faultyTraces, "list");
        messageErrorIf(list.empty(), "The attribute list "
                                     "in the xml tag "
                                     "faultyTraces has "
                                     "not been found");

        try {
            auto xmlFile =
                new rapidxml::file<>(list.c_str());
            auto doc = new rapidxml::xml_document<>();
            doc->parse<0>(xmlFile->data());

            XmlNode *root_node = doc->first_node("root");
            messageErrorIf(
                root_node == nullptr,
                "The xml tag root has not been found in " +
                    list);

            _fchecker = new FaultChecker(root_node);

            delete doc;
            delete xmlFile;
        } catch (exception &e) {
            std::cout
                << "Parsing error with xml file: " << list
                << ". "
                << "Reason: " << e.what() << endl;
            exit(1);
        }
    }

    messageInfo("Antecedent max variables: " +
                to_string(_maxVariablesAntecedent));
}

AteamMiner::~AteamMiner() {
    for (std::pair<const Template, Prop2DProps> &a :
         _antec2CandInProps) {
        for (auto &b : a.second) {
            for (auto &c : b.second) {
                delete c.second[0];
                delete c.second[1];
            }
        }
    }
}

void AteamMiner::_readTemplate(std::string formula) {

    messageErrorIf(
        formula.empty(),
        "Assertion template has not 'value' attribute");

    Template t = string2Template(formula);
    //======================= checking template
    //============================
    messageErrorIf(
        !(t.is(spot::op::G) && t[0].is(spot::op::Implies)),
        "Assertion template not supported: " + formula);

    //---------  step 1: antecedent (proposition or chain of
    //propositions)
    Template antecedent = support::getAntecedent(t);
    messageErrorIf(!(antecedent.is(spot::op::ap) ||
                     antecedent.is(spot::op::And)),
                   "Template's antecedent not supported: " +
                       formula);

    std::vector<size_t> chainOfNexts;
    support::getOffsetsFromChain(antecedent, chainOfNexts);

    // simple subset constraint
    for (size_t i = 1; i < chainOfNexts.size(); ++i)
        messageErrorIf(
            chainOfNexts[i - 1] >= chainOfNexts[i],
            "Not a simple subset PSL formula: " + formula);

    //---------  step 2: unique placeholders
    std::unordered_set<Template> placeHolders;
    size_t placeHolders_counter = 0;

    if (antecedent.is(spot::op::ap)) {
        placeHolders.insert(antecedent);
        ++placeHolders_counter;
    } else {
        for (auto &&atIndex : antecedent) {
            Template at = removeNext(atIndex);
            placeHolders.insert(at);
            ++placeHolders_counter;
        }
    }

    //---------  step 3: consequent (proposition)
    Template consequent = support::getConsequent(t);
    size_t consequent_offset = oden::removeNext(consequent);
    consequent = removeNext(consequent);

    messageErrorIf(chainOfNexts.back() > consequent_offset,
                   "Not a simple subset PSL formula: " +
                       formula);

    messageErrorIf(!(consequent.is(spot::op::ap)),
                   "Template's consequent not supported: " +
                       formula);

    placeHolders.insert(consequent);
    ++placeHolders_counter;

    messageErrorIf(placeHolders.size() !=
                       placeHolders_counter,
                   "Not unique Placeholders: " + formula);
    //----------------------------------------------------------------------
    _templates.push_back(t);
}
void AteamMiner::_readAssertionTemplates(
    XmlNode *templatesXml) {

    XmlNodeList templateList;
    getNodesFromName(templatesXml, "template",
                     templateList);
    messageErrorIf(templateList.empty(),
                   "No assertion template has been found!");

    for (XmlNode *tmp : templateList) {
        string formula = getAttributeValue(tmp, "value");
        messageErrorIf(
            formula.empty(),
            "Assertion template has not 'value' attribute");

        Template t = string2Template(formula);
        //======================= checking template
        //============================
        messageErrorIf(
            !(t.is(spot::op::G) &&
              t[0].is(spot::op::Implies)),
            "Assertion template not supported: " + formula);

        //---------  step 1: antecedent (proposition or
        //chain of propositions)
        Template antecedent = support::getAntecedent(t);
        messageErrorIf(
            !(antecedent.is(spot::op::ap) ||
              antecedent.is(spot::op::And)),
            "Template's antecedent not supported: " +
                formula);

        std::vector<size_t> chainOfNexts;
        support::getOffsetsFromChain(antecedent,
                                     chainOfNexts);

        // simple subset constraint
        for (size_t i = 1; i < chainOfNexts.size(); ++i)
            messageErrorIf(
                chainOfNexts[i - 1] >= chainOfNexts[i],
                "Not a simple subset PSL formula: " +
                    formula);

        //---------  step 2: unique placeholders
        std::unordered_set<Template> placeHolders;
        size_t placeHolders_counter = 0;

        if (antecedent.is(spot::op::ap)) {
            placeHolders.insert(antecedent);
            ++placeHolders_counter;
        } else {
            for (auto &&atIndex : antecedent) {
                Template at = removeNext(atIndex);
                placeHolders.insert(at);
                ++placeHolders_counter;
            }
        }

        //---------  step 3: consequent (proposition)
        Template consequent = support::getConsequent(t);
        size_t consequent_offset =
            oden::removeNext(consequent);
        consequent = removeNext(consequent);

        messageErrorIf(
            chainOfNexts.back() > consequent_offset,
            "Not a simple subset PSL formula: " + formula);

        messageErrorIf(
            !(consequent.is(spot::op::ap)),
            "Template's consequent not supported: " +
                formula);

        placeHolders.insert(consequent);
        ++placeHolders_counter;

        messageErrorIf(
            placeHolders.size() != placeHolders_counter,
            "Not unique Placeholders: " + formula);
        //----------------------------------------------------------------------
        _templates.push_back(t);
    }
}

void AteamMiner::mineProperties(
    ConeOfInfluence &cone,
    TraceRepository &traceRepository) {

    messageErrorIf(
        traceRepository.size() > 1,
        "Only a training trace is supported in A-TEAM");

    // the unique training trace
    Trace &trace = traceRepository[0];

    //============= step 2: make candidate proposition for
    //antecedents =========
    _makeCandidatePropositions(cone);

    // coverage of the mined assertions.
    double coverage = 0.0;

    // number of mined assertions
    int assertCounter = 0;

    //================ step 3: mining temporal assertions
    //======================
    List<Assertion> minedAssertions;
    for (Proposition *prop : cone.outPropositions) {
        //=============== DEBUG ======================
        messageInfo("PROP: " + oden::prop2String(*prop));
        //--------------------------------------------

        bool checkInvariant = false;
        for (const Template &templ : _templates) {

            // have we already checked if prop is an
            // invariant?
            if (!checkInvariant) {
                checkInvariant = true;
                if (isConstant(*prop)) {
                    messageInfo(oden::prop2String(*prop) +
                                " is an INVARIANT!");
                    Assertion *assertion =
                        makeInvariant(*prop);
                    minedAssertions.push_back(assertion);
                    // prop is an invariant. We can avoid
                    // mining temporal
                    // assertions with this proposition
                    goto check_coverage;
                }
            }

            messageInfo("Template: " +
                        template2String(templ));
            // mine temporal assertions
            _makeImply(templ, prop, minedAssertions);

        check_coverage:
            // check coverage
            while (!minedAssertions.empty()) {
                Assertion *assertion =
                    minedAssertions.pop_front();
                assertion->id = assertCounter++;

                double fault_coverage =
                    _getFaultCoverage(*assertion);
                cone.assertions.push_back(assertion);
                if (fault_coverage > coverage) {
                    coverage = fault_coverage;
                    messageInfo("Current coverage: " +
                                to_string(coverage));
                }
                if (coverage >= 1.0 ||
                    cone.assertions.size() >= 1000)
                    goto endMining;
            }
        }
    }
//--------------------------------------------------------------------------
endMining:
    messageInfo("Final coverage: " + to_string(coverage));
    saveCoverageReport(cone.assertions);
}

double AteamMiner::_getFaultCoverage(Assertion &a) {
    if (_fchecker == nullptr)
        return 0;

    _fchecker->check(a);
    return _fchecker->getCoverage();
}

bool AteamMiner::_makeImply(const Template &templ,
                            Proposition *prop,
                            List<Assertion> &assertions) {

    Template antecedent = support::getAntecedent(templ);
    Template consequent = support::getConsequent(templ);
    //    size_t offsetCons   = countNext(consequent);
    consequent = removeNext(consequent);

    // 1 - setting the research space for the antecedent
    // generator
    size_t l = prop->getMaxTime();
    traceInfo.initTraceInfo(l);

    for (size_t i = 0; i < prop->getMaxTime(); ++i)
        traceInfo.setGoal(i, prop->evaluate(i));

    // 2 - collects the candidate variables to create the
    // antecedents
    DecTreeVariables candidateVariables;
    _selectDCVariables(antecedent, *prop, 0,
                       candidateVariables);

    // 3 - setting the antecedent generator
    AntecedentGenerator antGen;
    antGen.maxPropositions = _maxVariablesAntecedent;
    // if the consequent is a BooleanVariable, then we also
    // save the off-set.
    // Otherwise, we only save the on-set
    //antGen.safeOffset = (dynamic_cast<BooleanVariable *>(prop) != nullptr || dynamic_cast<LogicToBool *>(prop) != nullptr); 
    antGen.safeOffset=false;

    // 4 - generate the antecedents justifying the
    // consequent
    traceInfo = antGen.makeAntecedents(candidateVariables,
                                       traceInfo);

    stringstream ss;
    ss << "True instants: " << traceInfo.initTrue;
    ss << " ,assertions: " << antGen.onSets.size();
    ss << ", coverage: "
       << DIV(traceInfo.reachedTrue, traceInfo.initTrue);
    messageInfo(ss.str());
    ss.str("");

    ss << "False instants: "
       << traceInfo.length - traceInfo.initTrue;
    ss << " ,assertions: " << antGen.offSets.size();
    ss << ", coverage: "
       << DIV(traceInfo.reachedFalse,
              (traceInfo.length - traceInfo.initTrue));
    messageInfo(ss.str());

    for (const set<Proposition *> &props : antGen.onSets) {

        auto *assertion = new Assertion();
        assertion->consequent = oden::copy(*prop);
        _finalizeAntecedent(*assertion, antecedent, props);

        assertions.push_back(assertion);
    }

    for (const set<Proposition *> &props : antGen.offSets) {
        auto *assertion = new Assertion();
        assertion->consequent = oden::copy(*prop);
            makeExpression<PropositionNot>(
                oden::copy(*prop));
        _finalizeAntecedent(*assertion, antecedent, props);

        assertions.push_back(assertion);
    }

    return !assertions.empty();
}

void AteamMiner::_finalizeAntecedent(
    Assertion &assertion, const Template &antecedent,
    const set<Proposition *> &props) {

    map<size_t, PropositionAnd *> offset2Prop;

    //=============== step 1: collect propositions in
    //offset2Prop map
    //============
    // a & X[2]b & c & X[1]d --> {(0: a&c); (1, d); (2, b)}
    for (Proposition *proposition : props) {
        size_t offset = 0;
        Proposition *atomicProp = nullptr;

        auto *maybeNext =
            dynamic_cast<PropositionNext *>(proposition);
        if (maybeNext == nullptr)
            atomicProp = proposition;
        else {
            offset = maybeNext->getOffset();
            atomicProp = &(maybeNext->getItem());
        }

        PropositionAnd *currentProp = offset2Prop[offset];

        if (currentProp == nullptr) {
            currentProp = new PropositionAnd();
            offset2Prop[offset] = currentProp;
        }

        currentProp->addItem(oden::copy(*atomicProp));
    }
    //--------------------------------------------------------------------------

    //========= step 2: move propositions in template's
    //placeholder ============
    // {(0: a&c); (1, d); (2, b)} --> ((a&c) & X(d) &
    // X(X(b)))
    if (antecedent.is(spot::op::ap)){
        assertion.t2p[antecedent] = offset2Prop[0];
        assertion.antecedent=offset2Prop[0];
    } else {
        for (auto at : antecedent) {
            size_t offset = countNext(at);
            at = removeNext(at);

            Proposition *p = offset2Prop[offset];
            assertion.t2p[at] =
                (p == nullptr)
                ? new BooleanConstant(true, 0)
                : p;
            assertion.antecedent=
                (p == nullptr)
                ? new BooleanConstant(true, 0)
                : p;
        }
    }




    //----------------------------------------------------------------------------
}

void AteamMiner::_makeCandidatePropositions(
    ConeOfInfluence &cone) {

    // (n.b. each template is G(antecedent -> consequent)
    for (const Template &temp : _templates) {
        Template antecedent = support::getAntecedent(temp);

        //============= (1) get the chain of next operators
        //in the antecedent
        std::vector<size_t> chainOfNexts;
        support::getOffsetsFromChain(antecedent,
                                     chainOfNexts);
        // chainOfNexts = (0 1 2)
        // Propositions = {a, b}
        // Propositions in the extended trace = {a, a`, a``,
        // b, b`, b``}, where:
        // a = a[t], a` = a[t+1], a``[t+2]
        // b = b[t], b` = b[t+1], b``[t+2]
        // t + offset is implemented by PropositionNext
        //--------------------------------------------------------------------------

        //========== (2) filling the vectors of atomic
        //proposition

        /*
    std::sort(begin(cone.inPropositions),end(cone.inPropositions),[](Proposition *p1,Proposition *p2){
            return oden::prop2String(*p1) < oden::prop2String(*p2);
            });
            */
        std::cout<<"Candidate antecedents:\n";
    for (auto e : cone.inPropositions) {
        std::cout << prop2String(*e) << "\n";
        /*
        for(size_t i=0;i<e->getMaxTime();i++){
            ofs<<e->evaluate(i)<<" ";
        }
        ofs <<"\n";
        */
    }
        _makeCandidatePropositions(
            cone.inPropositions, chainOfNexts,
            _antec2CandInProps[antecedent]);
        //_makeCandidatePropositions(cone.outPropositions,
        //chainOfNexts,
        //_antec2CandOutProps[antecedent]);
        //       _makeCandidatePropositions(cone.inoutPropositions,
        //       chainOfNexts,
        //       _antec2CandInoutProps[antecedent]);
        //--------------------------------------------------------------------------
    }
}

void AteamMiner::_makeCandidatePropositions(
    List<Proposition> &propositions,
    std::vector<size_t> chainOfNexts,
    Prop2DProps &candidatePropositions) {

    // candidatePropositions must be empty
    if (!candidatePropositions.empty())
        return;

    // p, q propositions, chainOfNexts: {0,1,2}
    // generated candidate propositions:
    // p -> {(0,{p, !p}), (1,{X(p), X(!p)}), (2,{X(X(p)),
    // X(X(!p))}) }
    // q -> {(0,{q, !q}), (1,{X(q), X(!q)}), (2,{X(X(q)),
    // X(X(!q))}) }
    // ....
    for (Proposition *p : propositions) {

        // only boolean variable can be used to define an
        // antecedent
        /*
        if (dynamic_cast<BooleanVariable *>(p) == nullptr)
            continue;
            */

        list<DelayedProposition> &delayedProps =
            candidatePropositions[p];

        auto rit = chainOfNexts.rbegin();
        for (; rit != chainOfNexts.rend(); ++rit) {
            size_t offset = *rit;
            DelayedProposition dProp;
            dProp.first = offset;

            dProp.second[0] = oden::copy(*p);
            dProp.second[1] =
                makeExpression<PropositionNot>(
                    oden::copy(*p));

            if (offset != 0) {
                dProp.second[0] = new PropositionNext(
                    dProp.second[0], offset);
                dProp.second[1] = new PropositionNext(
                    dProp.second[1], offset);
            }

            delayedProps.push_back(dProp);
        }
    }
}

void AteamMiner::_selectDCVariables(
    const Template &antecedent, Proposition &consequent,
    size_t offset, DecTreeVariables &dcVariables) {
    size_t counter = 0;

    // inputs are always candidate propositions as they are
    // never applied as
    // a consequent in a template
    Prop2DProps &inputProps =
        _antec2CandInProps[antecedent];
    for (auto &kv : inputProps) {
        Proposition *pp = kv.first;
        std::string ss = oden::prop2String(*pp);
        for (DelayedProposition &p : kv.second) {
            if (oden::prop2String(*kv.first) !=
                oden::prop2String(consequent)) {
                dcVariables[counter][0] = p.second[0];
                dcVariables[counter][1] = p.second[1];
                ++counter;
            }
        }
    }

    Prop2DProps &outputProps =
        _antec2CandOutProps[antecedent];
    for (auto &kv : outputProps) {
        for (DelayedProposition &p : kv.second) {
            if (oden::prop2String(*kv.first) !=
                oden::prop2String(consequent)) {
                dcVariables[counter][0] = p.second[0];
                dcVariables[counter][1] = p.second[1];
                ++counter;
            }
        }
    }

    Prop2DProps &inoutProps =
        _antec2CandInoutProps[antecedent];
    for (auto &kv : inoutProps) {
        for (DelayedProposition &p : kv.second) {
            if (!(kv.first == &consequent &&
                  p.first >= offset)) {
                dcVariables[counter][0] = p.second[0];
                dcVariables[counter][1] = p.second[1];
                ++counter;
            }
        }
    }
}

} // namespace ateam
