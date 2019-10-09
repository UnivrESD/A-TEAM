#pragma once
#include "oden/modules/PropositionMiner.hh"

using namespace oden;

namespace booleanVariables {

/// @brief BooleanVariables declaration.
///
/// This class defines two propositions for each boolean variable
/// in the cone of influence. (boolean a -> {a, !a})
///

class BooleanVariables : public modules::PropositionMiner {

  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing miner's parameters
    explicit BooleanVariables(XmlNode *data);

    /// @brief Destructor.
    ~BooleanVariables() override = default;

    void minePropositions(ConeOfInfluence &cone,
                          TraceRepository &traceRepository) override;
};

} // namespace booleanVariables
