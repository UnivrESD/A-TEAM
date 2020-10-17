#pragma once

#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief TraceReader declaration.
/// This is an interface for a generic trace reader module.
class TraceReader {

  public:
    /// @brief Destructor
    virtual ~TraceReader() = default;

    /// @brief An implementation of this method reads the simulation traces and
    /// generates a TraceRepository as a result.
    /// @return A TraceRepository object.
    virtual TraceRepository *readTraces() = 0;

    /// @brief Unsupported constructor.
    TraceReader(const TraceReader &other) = delete;

    /// @brief Unsupported operator
    TraceReader &operator=(const TraceReader &other) = delete;

  protected:

    /// @brief Constructor.
    /// @param data is the trace xmlData
    explicit TraceReader(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;

    /// @brief The methods reads a list of xml nodes following the pattern
    /// <direction name="var_name"   dir="var_direction" />
    /// to fill a map var_name->var_direction.
    /// @param directionList a list of xml nodes
    /// @param name2Dir a map var_name->var_direction
    void fillName2Dir(XmlNodeList &directionList,
                      std::map<std::string, VariableDirection> &name2Dir);

};

} // namespace modules
} // namespace oden
