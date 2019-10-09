#pragma once

#include "oden/classes/ConeOfInfluence.hh"
#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"

namespace oden {
namespace modules {

/// @brief PropositionMiner declaration.
/// This is an interface for a generic proposition miner module.
class PropositionMiner {

  public:
    /// @brief Destructor.
    virtual ~PropositionMiner() = default;

    /// @brief An implementation of this method analyzes the traces of a
    /// TraceRepository to mine propositions by combing arithmetic/logic
    /// operators with the variables of a given cone of influence.
    /// @param cone A cone of influence.
    /// @param traceRepository A repository of simulation traces.
    virtual void minePropositions(ConeOfInfluence &cone,
                                  TraceRepository &traceRepository) = 0;

    /// @brief Unsupported constructor.
    PropositionMiner(const PropositionMiner &other) = delete;

    /// @brief Unsupported operator
    PropositionMiner &operator=(const PropositionMiner &other) = delete;

  protected:
    /// @brief Constructor.
    explicit PropositionMiner(XmlNode *data);

    /// @brief The xml node containing the configuration
    /// parameters for the module.
    XmlNode *configuration;
};

} // namespace modules
} // namespace oden
