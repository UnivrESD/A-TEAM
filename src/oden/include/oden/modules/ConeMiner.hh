#pragma once

#include "oden/List.hh"
#include "oden/classes/ConeOfInfluence.hh"
#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief ConeMiner declaration.
/// This is an interface for a generic cone of influence miner module.
class ConeMiner {

  public:
    /// @brief Destructor.
    virtual ~ConeMiner() = default;

    /// @brief An implementation of this method generates
    /// cone of influences in some way.
    /// @param traceRepo A repository of simulation traces.
    /// @param cone A cone of influence.
    virtual void mineCones(TraceRepository &traceRepo,
                           List<ConeOfInfluence> &cones) = 0;

    /// @brief Unsupported constructor.
    ConeMiner(const ConeMiner &other) = delete;

    /// @brief Unsupported operator.
    ConeMiner &operator=(const ConeMiner &other) = delete;

  protected:
    /// @brief Constructor.
    explicit ConeMiner(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;
};

} // namespace modules
} // namespace oden
