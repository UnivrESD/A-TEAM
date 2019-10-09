#include "oden/odenUtils/propositionUtils.hh"
#include "oden/odenUtils/templateUtils.hh"
#include "oden/visitors/CopyVisitor.hh"
#include "oden/visitors/PeTraceChanger.hh"
#include "oden/visitors/PrinterVisitor.hh"

#include <sstream>

namespace oden {

std::string prop2String(Proposition &prop) {
    PrinterVisitor printer;
    prop.acceptVisitor(printer);
    return printer.get();
}

Proposition *copy(Proposition &prop) {
    CopyVisitor copy;
    prop.acceptVisitor(copy);
    return copy.get();
}

void changeTrace(Proposition &prop, Trace &trace) {
    PeTraceChanger peChanger;
    peChanger.setTrace(&trace);
    prop.acceptVisitor(peChanger);
}

Numeric string2Numeric(const std::string &val) {
    Numeric ret;
    std::stringstream ss(val);
    ss >> ret;

    return ret;
}

Logic string2Logic(const std::string &val) { return Logic(val); }

bool isConstant(Proposition &prop) {
    bool value = prop.evaluate(0);
    for (size_t time = 1; time < prop.getMaxTime(); ++time)
        if (prop.evaluate(time) != value)
            return false;
    return true;
}

Assertion *makeInvariant(Proposition &proposition) {

    Proposition *invariant = oden::copy(proposition);

    if (!invariant->evaluate(0))
        invariant = makeExpression<PropositionNot>(invariant);

    Template tmp           = string2Template("G(p)");
    auto *assertion        = new Assertion();
    assertion->templ       = tmp;
    assertion->t2p[tmp[0]] = invariant;

    return assertion;
}

} // namespace oden
