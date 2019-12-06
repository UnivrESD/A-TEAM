#pragma once

#include "oden/List.hh"
#include "oden/classes/atom/Atom.hh"
#include "oden/odenEnums.hh"

namespace oden {

/// @brief Expression declaration.
/// This class represents a generic numeric, logic or boolean expression.
template <BinaryOperator O, typename OT, typename ET>
class Expression : public ET {

    using ReturnType = typename std::conditional<
        std::is_same<ET, NumericExpression>::value, Numeric,
        typename std::conditional<std::is_same<ET, LogicExpression>::value,
                                  Logic, bool>::type>::type;

  public:
    /// @brief Constructor.
    Expression();

    /// @brief copy Constructor.
    /// @param other The other Expression to be copied.
    Expression(const Expression &other) = delete;

    /// @brief Destructor.
    ~Expression() override = default;

    /// @brief Evaluate the expression in a given simulation time.
    /// @param time The simulation time
    /// @return The value of the expression in the given simulation time.
    ReturnType evaluate(size_t time) override;

    /// @brief Accepts a visitor to visit the current expression.
    /// @param vis The visitor.
    void acceptVisitor(OdenVisitor &vis) override;

    size_t getMaxTime() override;

    /// @brief Assing operator
    Expression &operator=(const Expression &other) = delete;

    /// @brief Adds a new expression
    /// @param item The expression to be added in the current one.
    void addItem(OT *item);

    /// @brief Return the list of subexpressions.
    /// @return A reference to the list of subexpressions.
    List<OT> &getItems();

    /// @brief Return the number of subexpressions.
    /// @return number of subexpressions.
    size_t size();

    /// @brief Returns true, if the expression has no subexpressions.
    /// @return True if the expression size is 0, false otherwise.
    bool empty();

  private:
    // List of items.
    List<OT> _items;
};

// proposition
using PropositionAnd =
    Expression<BinaryOperator ::AND, Proposition, Proposition>;
using PropositionOr = Expression<BinaryOperator ::OR, Proposition, Proposition>;
using PropositionXor =
    Expression<BinaryOperator ::XOR, Proposition, Proposition>;
using PropositionEq = Expression<BinaryOperator ::EQ, Proposition, Proposition>;
using PropositionNeq = Expression<BinaryOperator ::NEQ, Proposition, Proposition>;
using PropositionNot =
    Expression<BinaryOperator ::NOT, Proposition, Proposition>;

// numeric
using NumericSum =
    Expression<BinaryOperator::SUM, NumericExpression, NumericExpression>;
using NumericSub =
    Expression<BinaryOperator::SUB, NumericExpression, NumericExpression>;
using NumericMul =
    Expression<BinaryOperator::MUL, NumericExpression, NumericExpression>;
using NumericDiv =
    Expression<BinaryOperator::DIV, NumericExpression, NumericExpression>;
using NumericEq =
    Expression<BinaryOperator::EQ, NumericExpression, Proposition>;
using NumericNeq =
    Expression<BinaryOperator::NEQ, NumericExpression, Proposition>;
using NumericGreater =
    Expression<BinaryOperator::GT, NumericExpression, Proposition>;
using NumericGreaterEq =
    Expression<BinaryOperator::GE, NumericExpression, Proposition>;
using NumericLess =
    Expression<BinaryOperator::LT, NumericExpression, Proposition>;
using NumericLessEq =
    Expression<BinaryOperator::LE, NumericExpression, Proposition>;

// logic
using LogicSum =
    Expression<BinaryOperator::SUM, LogicExpression, LogicExpression>;
using LogicSub =
    Expression<BinaryOperator::SUB, LogicExpression, LogicExpression>;
using LogicMul =
    Expression<BinaryOperator::MUL, LogicExpression, LogicExpression>;
using LogicDiv =
    Expression<BinaryOperator::DIV, LogicExpression, LogicExpression>;
using LogicBAnd =
    Expression<BinaryOperator::BAND, LogicExpression, LogicExpression>;
using LogicBOr =
    Expression<BinaryOperator::BOR, LogicExpression, LogicExpression>;
using LogicBXor =
    Expression<BinaryOperator::BXOR, LogicExpression, LogicExpression>;

using LogicEq  = Expression<BinaryOperator::EQ, LogicExpression, Proposition>;
using LogicNeq = Expression<BinaryOperator::NEQ, LogicExpression, Proposition>;
using LogicGreater =
    Expression<BinaryOperator::GT, LogicExpression, Proposition>;
using LogicGreaterEq =
    Expression<BinaryOperator::GE, LogicExpression, Proposition>;
using LogicLess = Expression<BinaryOperator::LT, LogicExpression, Proposition>;
using LogicLessEq =
    Expression<BinaryOperator::LE, LogicExpression, Proposition>;
using LogicNot =
    Expression<BinaryOperator::NOT, LogicExpression, LogicExpression>;

} // namespace oden

#include "Expression.i.hh"
