#pragma once

#include "oden/classes/ConeOfInfluence.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief PropertyPrinter declaration.
/// This is an interface for a generic property printer module.
class PropertyPrinter {

  public:
    /// @brief Destructor.
    virtual ~PropertyPrinter() = default;

    /// @brief An implementation of this module prints the assertions of
    /// a cone of the influence.
    /// @param cone A cone of influence
    virtual void print(ConeOfInfluence &cones) = 0;

    /// @brief Unsupported constructor.
    PropertyPrinter(const PropertyPrinter &other) = delete;

    /// @brief Unsupported operator
    PropertyPrinter &operator=(const PropertyPrinter &other) = delete;

  protected:
    /// @brief Constructor.
    explicit PropertyPrinter(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;
};

} // namespace modules
} // namespace oden
