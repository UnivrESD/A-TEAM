#include "TBPropositionMiner.hh"
#include "oden/classes/classes.hh"
#include "oden/odenUtils/odenUtils.hh"

#include <string>
#include <algorithm>

using namespace std;

namespace tbPropositionMiner {

namespace /**/ {

size_t countPlaceholders(Template templ) {
    size_t s = 0;
    templ.traverse(
        [](Template templ, size_t &numberOfLeaves) {
            if (templ.is(spot::op::ap)) {
                numberOfLeaves++;
            }
            return false;
        },
        s);

    return s;
}

int *permGenerator(int base[], int start, int stop, int *repo, int l) {
    if (start == l) {
        for (int i    = 0; i < l; i++)
            *(repo++) = base[i];
    } else {
        for (int i = start; i < stop; i++) {
            swap(base[start], base[i]);
            repo = permGenerator(base, start + 1, stop, repo, l);
            swap(base[start], base[i]);
        }
    }

    return repo;
}

} // namespace

TBPropositionMiner::TBPropositionMiner(XmlNode *data)
    : modules::PropositionMiner(data), _templates() {

    XmlNode *templatesXml = configuration->first_node("ConsequentTemplates");
    messageErrorIf(templatesXml == nullptr,
                   "The xml tag templates has not been found");

    XmlNodeList templateList;
    getNodesFromName(templatesXml, "template", templateList);
    messageErrorIf(templateList.empty(),
                   "No assertion template has been found!");

    for (XmlNode *tmp : templateList) {
        string formula = getAttributeValue(tmp, "value");
        messageErrorIf(formula.empty(), "template has not 'value' attribute");

        Template t = string2Template(formula);
        //======================= checking template ============================
        // TODO: ...
        //----------------------------------------------------------------------
        _templates.push_back(t);
    }
}

void TBPropositionMiner::minePropositions(ConeOfInfluence &cone,
                                          TraceRepository &traceRepository) {
    std::cout << "Mine propositions "
                 "===================================================\n";
    Trace &trace = traceRepository[0];

    assert(cone.outPropositions.size()==0);

    // base solution
    int *base = new int[cone.propositions.size()];
    for (int i  = 0; i < cone.propositions.size(); ++i)
        base[i] = i;

    for (Template templ : _templates) {
        messageInfo("Generating consequent with template: " + oden::template2String(templ));

        size_t placeHolders = countPlaceholders(templ);
        messageInfo("Number of placeholders: " + std::to_string(placeHolders));

        if (placeHolders > cone.propositions.size()) {
            messageWarning("Insufficient number of propositions!!!");
            continue;
        }

        int solutions = cone.propositions.size();
        for (int i = cone.propositions.size() - 1;
             i > cone.propositions.size() - placeHolders; --i)
            solutions *= i;

        messageInfo("Generating " + std::to_string(solutions) +
                    " propositions...");

        int *repo = new int[solutions * placeHolders];
        permGenerator(base, 0, cone.propositions.size(), repo, placeHolders);

        for (int s = 0; s < solutions; ++s) {

            size_t counter = 0;
            Proposition *p = _genProposition(templ, &repo[s * placeHolders],
                                             counter, cone.propositions);

            if (!isInvariant(p))
                cone.outPropositions.push_back(p);
            else{
                std::cout<<oden::prop2String(*p)<<" is an invariant!\n";
                delete p;
            }
        }

        delete[] repo;
    }

    std::cout << "generated consequents:\n";

    /*
    std::sort(begin(cone.outPropositions),end(cone.outPropositions),[](Proposition *p1,Proposition *p2){
            return oden::prop2String(*p1) < oden::prop2String(*p2);
            });
            */
    
    /*
    std::ofstream ofs;
  ofs.open ("Logicvars.txt", std::ofstream::out);
  */
    for (auto e : cone.outPropositions) {
        std::cout << prop2String(*e) << "\n";
        /*
        for(size_t i=0;i<e->getMaxTime();i++){
            ofs<<e->evaluate(i)<<" ";
        }
        ofs <<"\n";
        */
    }

    delete[] base;
}

Proposition *TBPropositionMiner::_genProposition(Template curr, int *repo,
                                                 size_t &counter,
                                                 List<Proposition> &outProps) {

    if (curr.is(spot::op::U)) {
        return new UntilOperator(
            _genProposition(curr[0], repo, counter, outProps),
            _genProposition(curr[1], repo, counter, outProps));
    }

    if (curr.is(spot::op::R)) {
        return new ReleaseOperator(
            _genProposition(curr[0], repo, counter, outProps),
            _genProposition(curr[1], repo, counter, outProps));
    }

    if (curr.is(spot::op::Not)) {
        auto *pN = new PropositionNot();
        pN->addItem(_genProposition(curr[0], repo, counter, outProps));
        return pN;
    }

    if (curr.is(spot::op::And)) {
        auto *pA = new PropositionAnd();
        pA->addItem(_genProposition(curr[0], repo, counter, outProps));
        pA->addItem(_genProposition(curr[1], repo, counter, outProps));

        for (unsigned i = 2; i < curr.size(); i++)
            pA->addItem(_genProposition(curr[i], repo, counter, outProps));

        return pA;
    }

    if (curr.is(spot::op::Or)) {
        auto *pO = new PropositionOr();
        pO->addItem(_genProposition(curr[0], repo, counter, outProps));
        pO->addItem(_genProposition(curr[1], repo, counter, outProps));

        for (unsigned i = 2; i < curr.size(); i++)
            pO->addItem(_genProposition(curr[i], repo, counter, outProps));

        return pO;
    }

    if (curr.is(spot::op::X)) {
        size_t offset = oden::countNext(curr);
        curr          = oden::removeNext(curr);

        Proposition *p = _genProposition(curr, repo, counter, outProps);

        Proposition *p1 = new PropositionNext(p, offset);
        return p1;
    }

    if (curr.is(spot::op::Equiv)) {
        auto *pO = new PropositionEq();
        pO->addItem(_genProposition(curr[0], repo, counter, outProps));
        pO->addItem(_genProposition(curr[1], repo, counter, outProps));
        return pO;
    }

    if (isAtomicProposition(curr))
        return oden::copy(*outProps[repo[counter++]]);

    messageError("Unsupported template: " + template2String(curr) + "\n");
    return nullptr;
}

bool TBPropositionMiner::isInvariant(Proposition *p) {
    bool val = p->evaluate(0);

    size_t time = 1;
    for (; time < p->getMaxTime() && (val == p->evaluate(time)); ++time)
        ;

    return time == p->getMaxTime();
}
}
