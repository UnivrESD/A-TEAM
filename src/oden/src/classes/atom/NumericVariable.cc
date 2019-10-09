#include "oden/OdenVisitor.hh"
#include "oden/classes/atom/Variable.hh"

namespace oden {

NumericVariable::NumericVariable(Numeric *v, const std::string &name,
                                 size_t max_time)
    : Variable_Base<Numeric>(name, max_time), _v(v) {
    // ntd
}

NumericVariable::NumericVariable(const NumericVariable &other)
    : Variable_Base<Numeric>(other._name, other._max_time), _v(other._v) {
    // ntd
}

Numeric NumericVariable::evaluate(size_t time) { return _v[time]; }

void NumericVariable::assign(size_t time, Numeric value) { _v[time] = value; }

NumericVariable &NumericVariable::operator=(const NumericVariable &other) {
    _v = other._v;
    return *this;
}

void NumericVariable::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }

} // namespace oden
