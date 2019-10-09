#pragma once
#include "oden/modules/PropositionMiner.hh"
#include <vector>

using namespace oden;

namespace tbPropositionMiner {

/// @brief TBPropositionMiner declaration.
///
///
///

class TBPropositionMiner : public modules::PropositionMiner {

  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing miner's parameters
    explicit TBPropositionMiner(XmlNode *data);

    /// @brief Destructor.
    ~TBPropositionMiner() override = default;

    void minePropositions(ConeOfInfluence &cone,
                          TraceRepository &traceRepository) override;

  private:
    Proposition *_genProposition(Template curr, int *repo, size_t &counter,
                                 List<Proposition> &outProps);

    bool isInvariant(Proposition *p);

    std::vector<Template> _templates;
};

} // namespace tbPropositionMiner
