#include "oden/visitors/CopyVisitor.hh"

//------------------------------------------------------------------------------
#define LEAF_NODE(LEAF, DEST)                                                  \
    void CopyVisitor::visit(LEAF &o) { DEST = new LEAF(o); }

#define EXPRESSION(OPERATOR, OPERAND, RESULT)                                  \
    void CopyVisitor::visit(OPERATOR &o) {                                     \
        auto *copy  = new OPERATOR();                                          \
        auto &items = o.getItems();                                            \
        for (auto *item : items) {                                             \
            item->acceptVisitor(*this);                                        \
            copy->addItem(OPERAND);                                            \
        }                                                                      \
        RESULT = copy;                                                         \
    }
//------------------------------------------------------------------------------

namespace oden {

CopyVisitor::CopyVisitor()
    : OdenVisitor(), _proposition(nullptr), _numeric(nullptr), _logic(nullptr) {
    // ntd
}

CopyVisitor::~CopyVisitor() { delete _proposition; }

Proposition *CopyVisitor::get() {
    Proposition *ret = _proposition;
    _proposition     = nullptr;
    return ret;
}

// proposition
LEAF_NODE(BooleanConstant, _proposition)
LEAF_NODE(BooleanVariable, _proposition)
EXPRESSION(PropositionAnd, _proposition, _proposition)
EXPRESSION(PropositionOr, _proposition, _proposition)
EXPRESSION(PropositionXor, _proposition, _proposition)
EXPRESSION(PropositionEq, _proposition, _proposition)
EXPRESSION(PropositionNeq, _proposition, _proposition)
EXPRESSION(PropositionNot, _proposition, _proposition)

void CopyVisitor::visit(PropositionNext &o) {
    o.getItem().acceptVisitor(*this);
    _proposition = new PropositionNext(_proposition, o.getOffset());
}
void CopyVisitor::visit(PropositionPast &o) {
    o.getItem().acceptVisitor(*this);
    _proposition = new PropositionPast(_proposition, o.getOffset());
}
void CopyVisitor::visit(PropositionBitSelector &o) {
    o.getItem().acceptVisitor(*this);
    _proposition = new PropositionBitSelector(_logic, o.getLowerBound(),o.getLowerBound());
}

void CopyVisitor::visit(UntilOperator &o) {
    o.getItem1().acceptVisitor(*this);
    Proposition *tmp = _proposition;
    _proposition     = nullptr;

    o.getItem2().acceptVisitor(*this);
    _proposition = new UntilOperator(tmp, _proposition);
}

void CopyVisitor::visit(ReleaseOperator &o) {
    o.getItem1().acceptVisitor(*this);
    Proposition *tmp = _proposition;
    _proposition     = nullptr;

    o.getItem2().acceptVisitor(*this);
    _proposition = new ReleaseOperator(tmp, _proposition);
}

// numeric
LEAF_NODE(NumericConstant, _numeric)
LEAF_NODE(NumericVariable, _numeric)
EXPRESSION(NumericSum, _numeric, _numeric)
EXPRESSION(NumericSub, _numeric, _numeric)
EXPRESSION(NumericMul, _numeric, _numeric)
EXPRESSION(NumericDiv, _numeric, _numeric)
EXPRESSION(NumericEq, _numeric, _proposition)
EXPRESSION(NumericNeq, _numeric, _proposition)
EXPRESSION(NumericLess, _numeric, _proposition)
EXPRESSION(NumericLessEq, _numeric, _proposition)
EXPRESSION(NumericGreater, _numeric, _proposition)
EXPRESSION(NumericGreaterEq, _numeric, _proposition)

void CopyVisitor::visit(NumericNext &o) {
    o.getItem().acceptVisitor(*this);
    _numeric = new NumericNext(_numeric, o.getOffset());
}

void CopyVisitor::visit(NumericPast &o) {
    o.getItem().acceptVisitor(*this);
    _numeric = new NumericPast(_numeric, o.getOffset());
}

// logic
LEAF_NODE(LogicConstant, _logic)
LEAF_NODE(LogicVariable, _logic)
EXPRESSION(LogicSum, _logic, _logic)
EXPRESSION(LogicSub, _logic, _logic)
EXPRESSION(LogicMul, _logic, _logic)
EXPRESSION(LogicDiv, _logic, _logic)
EXPRESSION(LogicBAnd, _logic, _logic)
EXPRESSION(LogicBOr, _logic, _logic)
EXPRESSION(LogicBXor, _logic, _logic)
EXPRESSION(LogicNot, _logic, _logic)
EXPRESSION(LogicEq, _logic, _proposition)
EXPRESSION(LogicNeq, _logic, _proposition)
EXPRESSION(LogicLess, _logic, _proposition)
EXPRESSION(LogicLessEq, _logic, _proposition)
EXPRESSION(LogicGreater, _logic, _proposition)
EXPRESSION(LogicGreaterEq, _logic, _proposition)

void CopyVisitor::visit(LogicNext &o) {
    o.getItem().acceptVisitor(*this);
    _logic = new LogicNext(_logic, o.getOffset());
}
void CopyVisitor::visit(LogicPast &o) {
    o.getItem().acceptVisitor(*this);
    _logic = new LogicPast(_logic, o.getOffset());
}
void CopyVisitor::visit(LogicBitSelector &o) {
    o.getItem().acceptVisitor(*this);
    _logic = new LogicBitSelector(_logic, o.getUpperBound(),o.getLowerBound());
}

} // namespace oden
