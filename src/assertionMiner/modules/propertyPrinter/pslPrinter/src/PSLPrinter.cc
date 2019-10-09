#include "PSLPrinter.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/propositionUtils.hh"

#include <iostream>
#include <spot/tl/print.hh>
#include <sstream>

using namespace std;
using namespace oden;

namespace pslPrinter {

PSLPrinter::PSLPrinter(XmlNode *data) : PropertyPrinter(data), _pslVisitor() {
    // ntd
}

void PSLPrinter::print(ConeOfInfluence &cone) {

    stringstream ss;
    ss << "vunit vu" << cone.name << " (__MODULE__) {\n\n"
       << "default clock = (posedge clk);\n\n";

    for (Assertion *assertion : cone.assertions) {
        ss << "PSL" << assertion->id << ": assert ";
        _printer(*assertion, assertion->templ, ss);
        ss << ";\n";
    }

    ss << "\n}\n";
    cout << ss.str() << endl;
}

void PSLPrinter::_printer(Assertion &assertion, Template templ,
                          stringstream &ss) {

    if (templ.is(spot::op::G)) {
        ss << "always( ";
        _printer(assertion, templ[0], ss);
        ss << " )";
        return;
    }

    if (templ.is(spot::op::X)) {
        unsigned int xCounter = 0;
        do {
            ++xCounter;
            templ = templ[0];
        } while (templ.is(spot::op::X));

        ss << "next[" << xCounter << "](";
        _printer(assertion, templ, ss);
        ss << ")";
        return;
    }

    if (templ.is(spot::op::And)) {
        ss << "(";
        for (unsigned int fIndex = 0; fIndex < templ.size() - 1; ++fIndex) {
            Template atomicTempl = templ[fIndex];
            _printer(assertion, atomicTempl, ss);
            ss << " && ";
        }

        _printer(assertion, templ[templ.size() - 1], ss);
        ss << ")";
        return;
    }

    if (templ.is(spot::op::Implies)) {
        Template antecedent = templ[0];
        Template consequent = templ[1];

        _printer(assertion, antecedent, ss);
        ss << " -> ";
        _printer(assertion, consequent, ss);

        return;
    }

    if (templ.is(spot::op::ap)) {
        Proposition *p = assertion.t2p[templ];
        messageErrorIf(p == nullptr,
                       "A proposition has not been set in the template!");

        p->acceptVisitor(_pslVisitor);
        ss << _pslVisitor.get();
        return;
    }

    spot::print_psl(std::cout, templ) << "\n";
    messageError("Unsupported operator!");
}

} // namespace pslPrinter
