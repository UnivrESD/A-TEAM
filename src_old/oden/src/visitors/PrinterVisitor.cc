#include "oden/visitors/PrinterVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
  void PrinterVisitor::visit(LEAF &o) { _ss << o.getName(); }

#define CONSTANT(LEAF)                                                         \
  void PrinterVisitor::visit(LEAF &o) { _ss << o.evaluate(0); }
#define BOOLEAN_CONSTANT(LEAF)                                                         \
  void PrinterVisitor::visit(LEAF &o) { _ss << (o.evaluate(0)?"true":"false"); }

#define EXPRESSION(NODE)                                                       \
  void PrinterVisitor::visit(oden::NODE &o) {                                  \
    auto &items = o.getItems();                                                \
                                                                               \
    if (!items.empty()) {                                                      \
      auto iterStop = items.end();                                             \
      auto iter = items.begin();                                               \
                                                                               \
      _ss << "(";                                                              \
      if (items.size() > 1) {                                                  \
        --iterStop;                                                            \
        for (; iter != iterStop; ++iter) {                                     \
          (*iter)->acceptVisitor(*this);                                       \
          _ss << " " << operators[ope::NODE] << " ";                           \
        }                                                                      \
      }                                                                        \
      (*iter)->acceptVisitor(*this);                                           \
      _ss << ")";                                                              \
    }                                                                          \
  }

#define EXPRESSION_LOGIC_TO_BOOL(NODE)          \
void PrinterVisitor::visit(oden::NODE &o) {\
  _ss << "((bool) ";                      \
  o.getItem().acceptVisitor(*this);       \
  _ss << ")";                             \
}                                         
#define EXPRESSION_NUMERIC_TO_LOGIC(NODE)          \
void PrinterVisitor::visit(oden::NODE &o) {\
  _ss << "((logic) ";                      \
  o.getItem().acceptVisitor(*this);       \
  _ss << ")";                             \
}                                         

#define EXPRESSION_BOOLEAN_BIT_SELECTION(NODE)\
void PrinterVisitor::visit(oden::NODE &o) {\
  _ss << "(";                              \
  _ss << "{";                              \
  o.getItem().acceptVisitor(*this);        \
  _ss << "}";                              \
  _ss << "[";                              \
  _ss << o.getLowerBound();                \
  _ss << "]";                              \
  _ss << ")";                              \
}

#define EXPRESSION_LOGIC_BIT_SELECTION(NODE)\
void PrinterVisitor::visit(oden::NODE &o) {\
  if (o.getLowerBound() == o.getUpperBound()) {\
    _ss << "(";                            \
    _ss << "{";                            \
    o.getItem().acceptVisitor(*this);      \
    _ss << "}";                            \
    _ss << "[";                            \
    _ss << o.getLowerBound();              \
    _ss << "]";                            \
    _ss << ")";                            \
  } else {                                 \
    _ss << "(";                            \
    _ss << "{";                            \
    o.getItem().acceptVisitor(*this);      \
    _ss << "}";                            \
    _ss << "[";                            \
    _ss << o.getUpperBound();              \
    _ss << ":";                            \
    _ss << o.getLowerBound();              \
    _ss << "]";                            \
    _ss << ")";                            \
  }                                        \
}                                          \

#define EXPRESSION_NEXT(NODE)                                                  \
  void PrinterVisitor::visit(oden::NODE &o) {                                  \
    _ss << "nexttime[" << o.getOffset() << "](";                               \
    o.getItem().acceptVisitor(*this);                                          \
    _ss << ")";                                                                \
  }
#define EXPRESSION_PAST(NODE)                                                  \
  void PrinterVisitor::visit(oden::NODE &o) {                                  \
    _ss << "$past(";                                                           \
    o.getItem().acceptVisitor(*this);                                          \
    _ss << ", " << o.getOffset() << ")";                                       \
  }
//------------------------------------------------------------------------------

namespace oden {

PrinterVisitor::PrinterVisitor() : OdenVisitor(), _ss() {

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

void PrinterVisitor::clear() {
  _ss.clear();
  _ss.str(std::string());
}

std::string PrinterVisitor::get() {
  std::string ret = _ss.str();
  clear();
  return ret;
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

void PrinterVisitor::visit(oden::PropositionNot &o) {
  _ss << operators[ope::PropositionNot];
  o.getItems()[0]->acceptVisitor(*this);
}

void PrinterVisitor::visit(oden::LogicNot &o) {
  _ss << operators[ope::LogicNot];
  o.getItems()[0]->acceptVisitor(*this);
}

void PrinterVisitor::visit(oden::UntilOperator &o) {
  _ss << "(";
  o.getItem1().acceptVisitor(*this);
  _ss << " " << operators[ope::Until] << " ";
  o.getItem2().acceptVisitor(*this);
  _ss << ")";
}

void PrinterVisitor::visit(oden::ReleaseOperator &o) {
  _ss << "(";
  o.getItem1().acceptVisitor(*this);
  _ss << " " << operators[ope::Release] << " ";
  o.getItem2().acceptVisitor(*this);
  _ss << ")";
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
