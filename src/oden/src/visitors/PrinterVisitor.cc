#include "oden/visitors/PrinterVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
    void PrinterVisitor::visit(LEAF &o) { _ss << o.getName(); }

#define CONSTANT(LEAF)                                                         \
    void PrinterVisitor::visit(LEAF &o) { _ss << o.evaluate(0); }

#define EXPRESSION(NODE)                                                       \
    void PrinterVisitor::visit(oden::NODE &o) {                                \
        auto &items = o.getItems();                                            \
                                                                               \
        if (!items.empty()) {                                                  \
            auto iterStop = items.end();                                       \
            auto iter     = items.begin();                                     \
                                                                               \
            _ss << "(";                                                        \
            if (items.size() > 1) {                                            \
                --iterStop;                                                    \
                for (; iter != iterStop; ++iter) {                             \
                    (*iter)->acceptVisitor(*this);                             \
                    _ss << " " << operators[ope::NODE] << " ";                 \
                }                                                              \
            }                                                                  \
            (*iter)->acceptVisitor(*this);                                     \
            _ss << ")";                                                        \
        }                                                                      \
    }

#define EXPRESSION_NEXT(NODE)                                                  \
    void PrinterVisitor::visit(oden::NODE &o) {                                \
        _ss << "X[" << o.getOffset() << "](";                                  \
        o.getItem().acceptVisitor(*this);                                      \
        _ss << ")";                                                            \
    }
//------------------------------------------------------------------------------

namespace oden {

PrinterVisitor::PrinterVisitor() : OdenVisitor(), _ss() {

    // proposition
    operators[ope::PropositionNot] = std::string("!");
    operators[ope::PropositionAnd] = std::string("&");
    operators[ope::PropositionOr]  = std::string("|");
    operators[ope::PropositionXor] = std::string("^");
    operators[ope::PropositionEq]  = std::string("=");

    // numeric
    operators[ope::NumericSum]       = std::string("+");
    operators[ope::NumericSub]       = std::string("-");
    operators[ope::NumericMul]       = std::string("*");
    operators[ope::NumericDiv]       = std::string("/");
    operators[ope::NumericEq]        = std::string("=");
    operators[ope::NumericNeq]       = std::string("!=");
    operators[ope::NumericGreater]   = std::string(">");
    operators[ope::NumericGreaterEq] = std::string(">=");
    operators[ope::NumericLess]      = std::string("<");
    operators[ope::NumericLessEq]    = std::string("<=");

    // logic
    operators[ope::LogicSum]       = std::string("+");
    operators[ope::LogicSub]       = std::string("-");
    operators[ope::LogicMul]       = std::string("*");
    operators[ope::LogicDiv]       = std::string("/");
    operators[ope::LogicBAnd]      = std::string("&");
    operators[ope::LogicBOr]       = std::string("|");
    operators[ope::LogicBXor]      = std::string("^");
    operators[ope::LogicNot]       = std::string("~");
    operators[ope::LogicEq]        = std::string("=");
    operators[ope::LogicNeq]       = std::string("!=");
    operators[ope::LogicGreater]   = std::string(">");
    operators[ope::LogicGreaterEq] = std::string(">=");
    operators[ope::LogicLess]      = std::string("<");
    operators[ope::LogicLessEq]    = std::string("<=");

    // temporal
    operators[ope::Next]    = std::string("X");
    operators[ope::Until]   = std::string("U");
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
CONSTANT(BooleanConstant)
EXPRESSION(PropositionAnd)
EXPRESSION(PropositionOr)
EXPRESSION(PropositionXor)
EXPRESSION(PropositionEq)
EXPRESSION_NEXT(PropositionNext)

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

} // namespace oden
