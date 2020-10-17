#include "oden/OdenVisitor.hh"
#include "oden/classes/atom/Variable.hh"

namespace oden {

BooleanVariable::BooleanVariable(unsigned int *v, const std::string &name,
                                 size_t max_time)
    : Variable_Base<bool>(name, max_time), _v(v) {
    // ntd
}

BooleanVariable::BooleanVariable(const BooleanVariable &other)
    : Variable_Base<bool>(other._name, other._max_time), _v(other._v) {
    // ntd
}
void BooleanVariable::deleteArray(){
    delete[] _v;
}

bool BooleanVariable::evaluate(size_t time) {
    size_t tPos          = time >> 5;
    unsigned int _buffer = _v[tPos];

    return (_buffer & (1 << (time & 31))) != 0;
}

void BooleanVariable::assign(size_t time, bool value) {
    if (value)
        _v[time >> 5] |= 1 << (time & 31);
    else
        _v[time >> 5] &= ~(1 << (time & 31));
}

BooleanVariable &BooleanVariable::operator=(const BooleanVariable &other) {
    _v = other._v;
    return *this;
}

void BooleanVariable::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }

} // namespace oden
