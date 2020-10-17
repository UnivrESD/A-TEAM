#pragma once

#include "oden/classes/atom/Atom.hh"
#include "oden/classes/atom/Constant.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

/// @brief TypeCast declaration.
/// This class represents the bit selector operator
template <typename ET,typename RT> class TypeCast : public RT {


  public:
    TypeCast(ET *e);

    using ReturnType = typename std::conditional<std::is_same<RT, LogicExpression>::value, Logic, bool>::type;
    /// @brief Copy constructor.
    TypeCast(const TypeCast &other) = delete;

    /// @brief Destructor.
    virtual ~TypeCast();

    /// @brief Evaluate the expression in a given simulation time.
    /// @param time The simulation time
    /// @return The value of the expression
    ReturnType evaluate(size_t time) override;

    /// @brief Accepts a visitor to visit the current object.
    /// @param vis The visitor.
    void acceptVisitor(OdenVisitor &vis) override;

    /// @brief Return the expression of the next operator
    /// @return A reference to the expression.
    ET &getItem();

    /// @brief Assing operator
    TypeCast &operator=(const TypeCast &other) = delete;

  private:
    // The evaluated expression at time t + offset
    ET *_e;
};
using LogicToBool = TypeCast<LogicExpression,Proposition>;
using NumericToLogic = TypeCast<NumericExpression,LogicExpression>;

} // namespace oden

#include "TypeCast.i.hh"
