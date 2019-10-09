#include "oden/visitors/PeTraceChanger.hh"

namespace oden {

PeTraceChanger::PeTraceChanger() : _trace(nullptr) {
    // ntd
}

void PeTraceChanger::setTrace(Trace *trace) { _trace = trace; }

void PeTraceChanger::visit(BooleanVariable &o) {
    if (_trace != nullptr) {
        auto found = _trace->_varName2varValues.find(o._name);
        if (found == _trace->_varName2varValues.end())
            return;

        o._v        = reinterpret_cast<unsigned int *>(found->second);
        o._max_time = _trace->getLength();
    }
}

void PeTraceChanger::visit(LogicVariable &o) {
    if (_trace != nullptr) {
        auto found = _trace->_varName2varValues.find(o._name);
        if (found == _trace->_varName2varValues.end())
            return;

        o._v        = reinterpret_cast<uint64_t *>(found->second);
        o._max_time = _trace->getLength();
    }
}

void PeTraceChanger::visit(NumericVariable &o) {
    if (_trace != nullptr) {
        auto found = _trace->_varName2varValues.find(o._name);
        if (found == _trace->_varName2varValues.end())
            return;

        o._v        = reinterpret_cast<Numeric *>(found->second);
        o._max_time = _trace->getLength();
    }
}

void PeTraceChanger::visit(UntilOperator &o) {
    o._inCache = false;
    o.getItem1().acceptVisitor(*this);
    o.getItem2().acceptVisitor(*this);
}

void PeTraceChanger::visit(ReleaseOperator &o) {
    o._inCache = false;
    o.getItem1().acceptVisitor(*this);
    o.getItem2().acceptVisitor(*this);
}

} // namespace oden
