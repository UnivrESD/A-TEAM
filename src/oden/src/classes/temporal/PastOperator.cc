#include "oden/classes/temporal/PastOperator.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <>
void PastOperator<NumericExpression>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <>
void PastOperator<LogicExpression>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> void PastOperator<Proposition>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> Numeric PastOperator<NumericExpression>::evaluate(size_t time) {
    if (time < _offset) {
        return _e->evaluate(0);
    } else {
        return _e->evaluate(time - _offset);
    }
}

template <> Logic PastOperator<LogicExpression>::evaluate(size_t time) {
    if (time < _offset) {
        return _e->evaluate(0);
    } else {
        return _e->evaluate(time - _offset);
    }
}

template <> bool PastOperator<Proposition>::evaluate(size_t time) {
    if (time < _offset) {
        return _e->evaluate(0);
    } else {
        return _e->evaluate(time - _offset);
    }
}

} // namespace oden
