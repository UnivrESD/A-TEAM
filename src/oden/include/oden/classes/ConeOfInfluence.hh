#pragma once

#include "oden/List.hh"
#include "oden/classes/DataType.hh"
#include "oden/classes/atom/Atom.hh"
#include "oden/types.hh"
#include <string>

namespace oden {

/// @brief ConeOfInfluence declaration.
/// This class represents a cone of influence.
/// It consists of the name, a list of propositions, variables, and assertions
class ConeOfInfluence {

  public:
    /// @brief Constructor.
    /// @param n The name of the cone of influence
    explicit ConeOfInfluence(const std::string &n);

    /// @brief Unsupported constructor.
    ConeOfInfluence(const ConeOfInfluence &other) = delete;

    /// @brief Destructor.
    ~ConeOfInfluence() = default;

    /// @brief A List of propositions among
    /// the input variables belonging to the cone.
    List<Proposition> inPropositions;

    /// @brief A List of propositions among
    /// the output variables belonging to the cone.
    List<Proposition> outPropositions;

    /// @brief A List of propositions among
    /// the input/output variables belonging to the cone.
    List<Proposition> inoutPropositions;

    /// @brief The list of propositions in the cone of influence.
    List<Proposition> propositions;

    /// @brief The list of in variables
    List<Proposition> inVariables;

    /// @brief The list of inout variables
    List<Proposition> inoutVariables;

    /// @brief The list of out variables
    List<Proposition> outVariables;

    /// @brief The list of mined assertions.
    List<Assertion> assertions;

    /// @brief Unsupported operator
    ConeOfInfluence &operator=(const ConeOfInfluence &other) = delete;

    // the name of the cone of influence
    const std::string name;
};

} // namespace oden
