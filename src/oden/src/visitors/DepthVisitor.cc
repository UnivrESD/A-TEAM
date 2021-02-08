#include "oden/visitors/DepthVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
  void DepthVisitor::visit(LEAF &o) {  }

#define CONSTANT(LEAF)                                                         \
  void DepthVisitor::visit(LEAF &o) {  }
#define BOOLEAN_CONSTANT(LEAF)                                                         \
  void DepthVisitor::visit(LEAF &o) {  }

#define EXPRESSION(NODE)                                                       \
  void DepthVisitor::visit(oden::NODE &o) {                                  \
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
void DepthVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);       \
}                                         
#define EXPRESSION_NUMERIC_TO_LOGIC(NODE)          \
void DepthVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);       \
}                                         

#define EXPRESSION_BOOLEAN_BIT_SELECTION(NODE)\
void DepthVisitor::visit(oden::NODE &o) {\
  o.getItem().acceptVisitor(*this);        \
}

#define EXPRESSION_LOGIC_BIT_SELECTION(NODE)\
void DepthVisitor::visit(oden::NODE &o) {\
  if (o.getLowerBound() == o.getUpperBound()) {\
    o.getItem().acceptVisitor(*this);      \
  } else {                                 \
    o.getItem().acceptVisitor(*this);      \
  }                                        \
}                                          \

#define EXPRESSION_NEXT(NODE)                                                  \
  void DepthVisitor::visit(oden::NODE &o) {                                  \
	  _maxDepth=o.getOffset()>_maxDepth?o.getOffset():_maxDepth;\
    o.getItem().acceptVisitor(*this);                                          \
  }
#define EXPRESSION_PAST(NODE)                                                  \
  void DepthVisitor::visit(oden::NODE &o) {                                  \
    o.getItem().acceptVisitor(*this);                                          \
  }
//------------------------------------------------------------------------------

namespace oden {

DepthVisitor::DepthVisitor() : OdenVisitor()  {

  // proposition
  operators[ope::PropositionNot] = std::string("!");
  operators[ope::PropositionAnd] = std::string("&&");
  operators[ope::PropositionOr] = std::string("||");
  operators[ope::PropositionXor] = std::string("^");
  operators[ope::PropositionEq] = std::string("==");
  operators[ope::PropositionNeq] = std::string("!=");

  // numeric
  operators[ope::NumericSum] = std::string("+");
  operators[ope::NumericSub] = std::string("-");
  operators[ope::NumericMul] = std::string("*");
  operators[ope::NumericDiv] = std::string("/");
  operators[ope::NumericEq] = std::string("==");
  operators[ope::NumericNeq] = std::string("!=");
  operators[ope::NumericGreater] = std::string(">");
  operators[ope::NumericGreaterEq] = std::string(">=");
  operators[ope::NumericLess] = std::string("<");
  operators[ope::NumericLessEq] = std::string("<=");

  // logic
  operators[ope::LogicSum] = std::string("+");
  operators[ope::LogicSub] = std::string("-");
  operators[ope::LogicMul] = std::string("*");
  operators[ope::LogicDiv] = std::string("/");
  operators[ope::LogicBAnd] = std::string("&");
  operators[ope::LogicBOr] = std::string("|");
  operators[ope::LogicBXor] = std::string("^");
  operators[ope::LogicNot] = std::string("~");
  operators[ope::LogicEq] = std::string("==");
  operators[ope::LogicNeq] = std::string("!=");
  operators[ope::LogicGreater] = std::string(">");
  operators[ope::LogicGreaterEq] = std::string(">=");
  operators[ope::LogicLess] = std::string("<");
  operators[ope::LogicLessEq] = std::string("<=");

  // temporal
  operators[ope::Next] = std::string("nexttime");
  operators[ope::Past] = std::string("$past");
  operators[ope::Until] = std::string("U");
  operators[ope::Release] = std::string("R");
}

void DepthVisitor::clear() {
}

int DepthVisitor::get() {
  return _maxDepth;
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

void DepthVisitor::visit(oden::PropositionNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}

void DepthVisitor::visit(oden::LogicNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}

void DepthVisitor::visit(oden::UntilOperator &o) {
  o.getItem1().acceptVisitor(*this);
  o.getItem2().acceptVisitor(*this);
}

void DepthVisitor::visit(oden::ReleaseOperator &o) {
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
