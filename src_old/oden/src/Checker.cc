#include "oden/Checker.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/propositionUtils.hh"
#include "oden/odenUtils/templateUtils.hh"

// TODO doc.
namespace oden {

Checker::Checker() : _traceLength(0) {
    // ntd
}

void Checker::_updatePointers2Trace(Assertion &assertion, Trace *trace) {
    for (auto &kv : assertion.t2p) {
        messageErrorIf(kv.second == nullptr,
                       "A propoisition has not been set in the assertion!");
        changeTrace(*kv.second, *trace);
    }
}

bool Checker::evaluate(Assertion &assertion, TraceRepository &traces) {

    for (size_t traceId = 0; traceId < traces.size(); ++traceId)
        if (!evaluate(assertion, traces[traceId]))
            return false;

    return true;
}

bool Checker::evaluate(Assertion &assertion, Trace &trace) {

    if (!assertion.templ.is(spot::op::G))
        messageError("Only Always assertions are supported!");

    Template templ = assertion.templ[0];
    _updatePointers2Trace(assertion, &trace);

    _traceLength = trace.getLength();
    for (size_t instant = 0; instant < _traceLength; ++instant)
        if (!_evaluate(assertion, templ, instant))
            return false;

    return true;
}

bool Checker::_evaluate(Assertion &assertion, const Template &templ,
                        size_t instant) {

    if (templ.is(spot::op::Implies)) {
        //==== checking antecedent =============================================
        Template antecedent = templ[0];
        if (isAtomicProposition(antecedent)) {
            if (!assertion.t2p[antecedent]->evaluate(instant))
                return true;
        } else {
            for (Template subFormula : antecedent)
                if (!_evaluate(assertion, subFormula, instant))
                    return true;
        }
        //---------------------------------------------------------------------

        //=================== checking consequent ==============================
        Template consequent = templ[1];
        return _evaluate(assertion, consequent, instant);
        //----------------------------------------------------------------------
    }

    if (templ.is(spot::op::X)) {
        size_t offsetOp = countNext(templ);
        Template op     = removeNext(templ);

        size_t nextInstant = instant + offsetOp;
        return _evaluate(assertion, op, nextInstant);
    }

    if (isAtomicProposition(templ)) {
        return (instant < _traceLength)
                   ? assertion.t2p[templ]->evaluate(instant)
                   : true;
    }

    messageError("Unsupported operator: " + template2String(templ));
    return false;
}

} // namespace oden
