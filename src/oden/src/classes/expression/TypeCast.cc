#include "oden/classes/expression/TypeCast.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <>
void TypeCast<LogicExpression, Proposition>::acceptVisitor(
  OdenVisitor &vis) {
  vis.visit(*this);
}

template <>
void TypeCast<NumericExpression, LogicExpression>::acceptVisitor(
  OdenVisitor &vis) {
  vis.visit(*this);
}


template <>
bool TypeCast<LogicExpression, Proposition>::evaluate(size_t time) {
         return _e->evaluate(time).getValue();
}
template <>
Logic TypeCast<NumericExpression, LogicExpression>::evaluate(size_t time) {
         return Logic(_e->evaluate(time),32);
}

} // namespace oden
