#pragma once

#include "../Logic_t.hh"
#include <cstddef>

namespace oden {

// Forwards declaration of base class Visitor
class OdenVisitor;

/// @brief An Atom can represent either a Variable or a Constant.
/// It only provides the base methods evaluate and visit.
template <typename T> class Atom {
  public:
    /// @brief Destructor.
    virtual ~Atom() = default;

    /// @brief Returns the value of the atom in the given simulation time
    /// @param time The simulation time
    /// @return The value of the atom
    virtual T evaluate(size_t time) = 0;

    /// @brief Accepts a visitor to visit the current object.
    /// @param vis The visitor.
    virtual void acceptVisitor(OdenVisitor &vis) = 0;

    /// @brief Returns the largest simulation time that can be provided to
    /// the method evaluate.
    virtual size_t getMaxTime();

  protected:
    /// @brief Constructor of an Atom
    /// @param max_time the largest simulation time that can be provided to
    /// the method evaluate.
    explicit Atom(size_t max_time);

    // the largest simulation time for the method evaluate.
    size_t _max_time;
};

using Numeric = float;
using Logic   = Logic_t;

using NumericExpression = Atom<Numeric>;
using LogicExpression   = Atom<Logic>;
using Proposition       = Atom<bool>;

} // namespace oden

#include "Atom.i.hh"
