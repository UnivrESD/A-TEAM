#include "oden/classes/expression/BitSelector.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <> void BitSelector<LogicExpression,LogicExpression>::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}
template <> void BitSelector<LogicExpression,Proposition>::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> Logic BitSelector<LogicExpression,LogicExpression>::evaluate(size_t time) {
          return Logic(
          (static_cast<uint64_t>(((1 << (_upper_bound - _lower_bound + 1)) - 1) << _lower_bound) & _e->evaluate(time).getValue()), static_cast<uint8_t>(_upper_bound - _lower_bound + 1));
}
template <> bool BitSelector<LogicExpression,Proposition>::evaluate(size_t time) {
    messageErrorIf(_upper_bound!=_lower_bound,"Single bit selector index error");

          return static_cast<uint64_t>(((1 << (_upper_bound - _lower_bound + 1)) - 1) << _lower_bound) & _e->evaluate(time).getValue();
}


} // namespace oden
