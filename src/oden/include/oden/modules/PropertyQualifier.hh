#pragma once

#include "oden/classes/ConeOfInfluence.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief PropertyQualification declaration.
/// This is an interface for a generic property qualification module.
class PropertyQualifier {
  public:
    /// @brief Destructor.
    virtual ~PropertyQualifier() = default;

    /// @brief An implementation of this module qualify the assertions of
    /// a cone of the influence.
    /// @param cone A cone of influence
    virtual void qualify(ConeOfInfluence &cones) = 0;

    /// @brief Unsupported constructor.
    PropertyQualifier(const PropertyQualifier &other) = delete;

    /// @brief Unsupported operator
    PropertyQualifier &operator=(const PropertyQualifier &other) = delete;

  protected:
    /// @brief Constructor.
    explicit PropertyQualifier(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;
};

} // namespace modules
} // namespace oden
