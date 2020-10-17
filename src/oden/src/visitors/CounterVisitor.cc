#include "oden/visitors/CounterVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
  void CounterVisitor::visit(LEAF &o) { counter++; }

#define CONSTANT(LEAF)                                                         \
  void CounterVisitor::visit(LEAF &o) { counter++; }
#define BOOLEAN_CONSTANT(LEAF)                                                         \
  void CounterVisitor::visit(LEAF &o) { counter++; }

#define EXPRESSION(NODE)                                                       \
  void CounterVisitor::visit(oden::NODE &o) {                                  \
    auto &items = o.getItems();                                                \
                                                                               \
    if (!items.empty()) {                                                      \
      auto iterStop = items.end();                                             \
      auto iter = items.begin();                                               \
                                                                               \
      if (items.size() > 1) {                                                  \
        --iterStop;                                                            \
        for (; iter != iterStop; ++iter) {                                     \
          (*iter)->acceptVisitor(*this);                                       \
        }                                                                      \
      }                                                                        \
      (*iter)->acceptVisitor(*this);                                           \
    }                                                                          \
  }

#define EXPRESSION_LOGIC_TO_BOOL(NODE)          \
void CounterVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);       \
}                                         
#define EXPRESSION_NUMERIC_TO_LOGIC(NODE)          \
void CounterVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);       \
}                                         

#define EXPRESSION_BOOLEAN_BIT_SELECTION(NODE)\
void CounterVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);        \
}

#define EXPRESSION_LOGIC_BIT_SELECTION(NODE)\
void CounterVisitor::visit(oden::NODE &o) {\
  if (o.getLowerBound() == o.getUpperBound()) {\
    o.getItem().acceptVisitor(*this);      \
  } else {                                 \
    o.getItem().acceptVisitor(*this);      \
  }                                        \
}                                          \

#define EXPRESSION_NEXT(NODE)                                                  \
  void CounterVisitor::visit(oden::NODE &o) {                                  \
    o.getItem().acceptVisitor(*this);                                          \
    c_next_counter = o.getOffset();                                            \
  }
  
#define EXPRESSION_PAST(NODE)                                                  \
  void CounterVisitor::visit(oden::NODE &o) {                                  \
    o.getItem().acceptVisitor(*this);                                          \
  }
//------------------------------------------------------------------------------

namespace oden {

CounterVisitor::CounterVisitor() : OdenVisitor(), counter(0), c_next_counter(0) {

}

void CounterVisitor::clear() {
}


int CounterVisitor::get() {
  int temp = counter;
  clear();
  counter = 0;
  return temp;
}

int CounterVisitor::get_next() {
  int temp = c_next_counter;
  clear();
  c_next_counter = 0;
  return temp;
}

// proposition
VARIABLE(BooleanVariable)
BOOLEAN_CONSTANT(BooleanConstant)
EXPRESSION(PropositionAnd)
EXPRESSION(PropositionOr)
EXPRESSION(PropositionXor)
EXPRESSION(PropositionEq)
EXPRESSION(PropositionNeq)
EXPRESSION_NEXT(PropositionNext)
EXPRESSION_PAST(PropositionPast)
EXPRESSION_LOGIC_TO_BOOL(LogicToBool)

void CounterVisitor::visit(oden::PropositionNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}

void CounterVisitor::visit(oden::LogicNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}

void CounterVisitor::visit(oden::UntilOperator &o) {
  o.getItem1().acceptVisitor(*this);
  o.getItem2().acceptVisitor(*this);
}

void CounterVisitor::visit(oden::ReleaseOperator &o) {
  o.getItem1().acceptVisitor(*this);
  o.getItem2().acceptVisitor(*this);
}

// numeric
VARIABLE(NumericVariable)
CONSTANT(NumericConstant)
EXPRESSION(NumericSum)
EXPRESSION(NumericSub)
EXPRESSION(NumericMul)
EXPRESSION(NumericDiv)
EXPRESSION(NumericEq)
EXPRESSION(NumericNeq)
EXPRESSION(NumericGreater)
EXPRESSION(NumericGreaterEq)
EXPRESSION(NumericLess)
EXPRESSION(NumericLessEq)
EXPRESSION_NEXT(NumericNext)
EXPRESSION_PAST(NumericPast)

// logic
VARIABLE(LogicVariable)
CONSTANT(LogicConstant)
EXPRESSION(LogicSum)
EXPRESSION(LogicSub)
EXPRESSION(LogicMul)
EXPRESSION(LogicDiv)
EXPRESSION(LogicBAnd)
EXPRESSION(LogicBOr)
EXPRESSION(LogicBXor)
EXPRESSION(LogicEq)
EXPRESSION(LogicNeq)
EXPRESSION(LogicGreater)
EXPRESSION(LogicGreaterEq)
EXPRESSION(LogicLess)
EXPRESSION(LogicLessEq)
EXPRESSION_NEXT(LogicNext)
EXPRESSION_PAST(LogicPast)
EXPRESSION_LOGIC_BIT_SELECTION(LogicBitSelector)
EXPRESSION_NUMERIC_TO_LOGIC(NumericToLogic)

} // namespace oden
