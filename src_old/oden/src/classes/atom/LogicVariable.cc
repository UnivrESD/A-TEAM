#include "oden/OdenVisitor.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

using namespace applicationUtils;

LogicVariable::LogicVariable(uint64_t *v, uint8_t size, const std::string &name,
                             size_t max_time)
    : Variable_Base<Logic>(name, max_time), _v(v), _size(size), _mask(0),
      _valuesInside(0) {

    messageErrorIf(size > 64, "Not supported size for Logic");

    // Setting the mask to read only _size bits
    _mask         = (1 << _size) - 1;
    _valuesInside = (_bits4Logic*8) / _size;
}

LogicVariable::LogicVariable(const LogicVariable &other)
    : Variable_Base<Logic>(other._name, other._max_time), _v(other._v),
      _size(other._size), _mask(other._mask),
      _valuesInside(other._valuesInside) {
    // ntd
}

Logic LogicVariable::evaluate(size_t time) {
    if (_size > 32)
        return {_v[time], _size};

    size_t tPos    = time / _valuesInside;
    size_t shift   = _size * (time % _valuesInside);
    uint64_t value = _v[tPos] & (_mask << shift);

    return {value >> shift, _size};
}

void LogicVariable::assign(size_t time, Logic value) {
    if (_size > 32) {
        _v[time] = value.getValue();
        return;
    }

    size_t tPos         = time / _valuesInside;
    uint64_t traceValue = _v[tPos];

    size_t shift = _size * (time % _valuesInside);
    value        = value << shift;

    // delete value
    traceValue = traceValue & ~(_mask << shift);

    // set new value
    _v[tPos] = traceValue | value.getValue();
}

LogicVariable &LogicVariable::operator=(const LogicVariable &other) {
    _name         = other._name;
    _v            = other._v;
    _size         = other._size;
    _mask         = other._mask;
    _valuesInside = other._valuesInside;
    return *this;
}

void LogicVariable::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }

} // namespace oden
