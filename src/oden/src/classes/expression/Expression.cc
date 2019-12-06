#include "oden/classes/expression/Expression.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

//==== Call to Visitor's methods ===============================================
#define VISITOR_CALL(Operator, ET, OT)                                         \
    template <>                                                                \
    void Expression<BinaryOperator::Operator, ET, OT>::acceptVisitor(          \
        OdenVisitor &vis) {                                                    \
        vis.visit(*this);                                                      \
    }

// proposition
VISITOR_CALL(AND, Proposition, Proposition)
VISITOR_CALL(OR, Proposition, Proposition)
VISITOR_CALL(XOR, Proposition, Proposition)
VISITOR_CALL(EQ, Proposition, Proposition)
VISITOR_CALL(NEQ, Proposition, Proposition)
VISITOR_CALL(NOT, Proposition, Proposition)

// numeric
VISITOR_CALL(SUM, NumericExpression, NumericExpression)
VISITOR_CALL(SUB, NumericExpression, NumericExpression)
VISITOR_CALL(MUL, NumericExpression, NumericExpression)
VISITOR_CALL(DIV, NumericExpression, NumericExpression)
VISITOR_CALL(EQ, NumericExpression, Proposition)
VISITOR_CALL(NEQ, NumericExpression, Proposition)
VISITOR_CALL(GT, NumericExpression, Proposition)
VISITOR_CALL(GE, NumericExpression, Proposition)
VISITOR_CALL(LT, NumericExpression, Proposition)
VISITOR_CALL(LE, NumericExpression, Proposition)

// logic
VISITOR_CALL(SUM, LogicExpression, LogicExpression)
VISITOR_CALL(SUB, LogicExpression, LogicExpression)
VISITOR_CALL(MUL, LogicExpression, LogicExpression)
VISITOR_CALL(DIV, LogicExpression, LogicExpression)
VISITOR_CALL(BAND, LogicExpression, LogicExpression)
VISITOR_CALL(BOR, LogicExpression, LogicExpression)
VISITOR_CALL(BXOR, LogicExpression, LogicExpression)
VISITOR_CALL(EQ, LogicExpression, Proposition)
VISITOR_CALL(NEQ, LogicExpression, Proposition)
VISITOR_CALL(GT, LogicExpression, Proposition)
VISITOR_CALL(GE, LogicExpression, Proposition)
VISITOR_CALL(LT, LogicExpression, Proposition)
VISITOR_CALL(LE, LogicExpression, Proposition)
VISITOR_CALL(NOT, LogicExpression, LogicExpression)
//------------------------------------------------------------------------------

//==== evaluate methods for propositions =======================================
template <>
bool Expression<BinaryOperator::AND, Proposition, Proposition>::evaluate(
    size_t time) {

    for (Proposition *prop : _items)
        if (!prop->evaluate(time))
            return false;

    return true;
}

template <>
bool Expression<BinaryOperator::OR, Proposition, Proposition>::evaluate(
    size_t time) {

    for (Proposition *prop : _items)
        if (prop->evaluate(time))
            return true;

    return false;
}

template <>
bool Expression<BinaryOperator::XOR, Proposition, Proposition>::evaluate(
    size_t time) {
    if (_items.size() < 2)
        return false;

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret ^ _items[i]->evaluate(time);

    return ret;
}

template <>
bool Expression<BinaryOperator::EQ, Proposition, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) == _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NEQ, Proposition, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) != _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NOT, Proposition, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 1)
        return false;

    return !_items[0]->evaluate(time);
}
//------------------------------------------------------------------------------

//==== evaluate methods for numeric ============================================
template <>
Numeric
Expression<BinaryOperator::SUM, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
    if (_items.size() < 2)
        return 0;

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret += _items[i]->evaluate(time);

    return ret;
}

template <>
Numeric
Expression<BinaryOperator::SUB, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
    if (_items.size() < 2)
        return 0;

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret -= _items[i]->evaluate(time);

    return ret;
}

template <>
Numeric
Expression<BinaryOperator::MUL, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
    if (_items.size() < 2)
        return 0;

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret *= _items[i]->evaluate(time);

    return ret;
}

template <>
Numeric
Expression<BinaryOperator::DIV, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
    if (_items.size() < 2)
        return 0;

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret /= _items[i]->evaluate(time);

    return ret;
}

template <>
bool Expression<BinaryOperator::EQ, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) == _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NEQ, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) != _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GT, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) > _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GE, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) >= _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LT, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) < _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LE, NumericExpression, Proposition>::evaluate(
    size_t time) {

    return _items.size() == 2 &&
           _items[0]->evaluate(time) <= _items[1]->evaluate(time);
}
//------------------------------------------------------------------------------

//==== evaluate methods for logic ==============================================
template <>
Logic Expression<BinaryOperator::SUM, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret + _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::SUB, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret - _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::MUL, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret * _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::DIV, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret / _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::BAND, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret & _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::BOR, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret | _items[i]->evaluate(time);

    return ret;
}

template <>
Logic Expression<BinaryOperator::BXOR, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() < 2)
        return {0, 0};

    auto ret = _items[0]->evaluate(time);
    for (size_t i = 1; i < _items.size(); ++i)
        ret = ret ^ _items[i]->evaluate(time);

    return ret;
}

template <>
bool Expression<BinaryOperator::EQ, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) == _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NEQ, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) != _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GT, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) > _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GE, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) >= _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LT, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) < _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LE, LogicExpression, Proposition>::evaluate(
    size_t time) {
    if (_items.size() != 2)
        return false;

    return _items[0]->evaluate(time) <= _items[1]->evaluate(time);
}

template <>
Logic Expression<BinaryOperator::NOT, LogicExpression,
                 LogicExpression>::evaluate(size_t time) {
    if (_items.size() != 1)
        return {0, 0};

    return ~_items[0]->evaluate(time);
}
//------------------------------------------------------------------------------
}
