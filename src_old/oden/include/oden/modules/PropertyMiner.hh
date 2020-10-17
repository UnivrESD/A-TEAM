#pragma once

#include "oden/classes/ConeOfInfluence.hh"
#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief PropertyMiner declaration.
/// This is an interface for a generic property miner module.
class PropertyMiner {

  public:
    /// @brief Destructor.
    virtual ~PropertyMiner() = default;

    /// @brief An implementation of this method analyzes the traces of a
    /// TraceRepository to mine temporal assertions by combing temporal
    /// operators with the propositions of a given cone of influence.
    /// @param cone A cone of influence.
    /// @param traceRepository A repository of simulation traces.
    virtual void mineProperties(ConeOfInfluence &cone,
                                TraceRepository &traceRepository) = 0;

    /// @brief Unsupported constructor.
    PropertyMiner(const PropertyMiner &other) = delete;

    /// @brief Unsupported operator
    PropertyMiner &operator=(const PropertyMiner &other) = delete;

  protected:
    /// @brief Constructor.
    explicit PropertyMiner(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;
};

} // namespace modules
} // namespace oden
