#include "oden/classes/temporal/NextOperator.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <>
void NextOperator<NumericExpression>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <>
void NextOperator<LogicExpression>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> void NextOperator<Proposition>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> Numeric NextOperator<NumericExpression>::evaluate(size_t time) {
    if ((time + _offset) >= _max_time) {
        return _e->evaluate(_max_time - 1);
    } else {
        return _e->evaluate(_offset + time);
    }
}

template <> Logic NextOperator<LogicExpression>::evaluate(size_t time) {
    if ((time + _offset) >= _max_time) {
        return _e->evaluate(_max_time - 1);
    } else {
        return _e->evaluate(_offset + time);
    }
}

template <> bool NextOperator<Proposition>::evaluate(size_t time) {
    if ((time + _offset) >= _max_time) {
        return _e->evaluate(_max_time - 1);
    } else {
        return _e->evaluate(_offset + time);
    }
}

} // namespace oden
