#pragma once

#include "oden/Checker.hh"
#include "oden/modules/PropertyMiner.hh"
#include "oden/types.hh"
#include "oden/visitors/visitors.hh"

#include "FaultChecker.hh"
#include "supportTypes.hh"

#include <map>
#include <set>
#include <vector>

using namespace std;
using namespace oden;

namespace ateam {

/// @brief Ateam property miner declaration.
/// This class mines temporal assertions by using assertion templates
class AteamMiner : public modules::PropertyMiner {

  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing the miner's parameters
    explicit AteamMiner(XmlNode *xmlNode);

    /// @brief Copy constructor.
    /// @param other The AteamMiner to be copied.
    AteamMiner(const AteamMiner &other) = delete;

    /// @brief Assignment operator
    /// @param other The AteamMiner to be copied.
    AteamMiner &operator=(const AteamMiner &other) = delete;

    /// @brief Destructor.
    ~AteamMiner() override = default;

    /// @brief mineProperties.
    /// @param cone The cone of influence
    /// @param traceRepository The trace repository used by the miner
    void mineProperties(ConeOfInfluence &cone,
                        TraceRepository &traceRepository) override;

  private:
    // assertion checker for the faulty traces set
    FaultChecker *_fchecker;

    // template's antecedent -> set of candidate propositions (input)
    std::map<Template, Prop2DProps> _antec2CandInProps;

    // template's antecedent -> set of candidate propositions (output)
    std::map<Template, Prop2DProps> _antec2CandOutProps;

    // template's antecedent -> set of candidate propositions (input/output)
    std::map<Template, Prop2DProps> _antec2CandInoutProps;

    // vector of user defined templates
    std::vector<Template> _templates;

    // the maximum number of variable in an assertion's antecedent
    size_t _maxVariablesAntecedent;

    //TODO
    // reads and validates user-defined templates
    void _readAssertionTemplates(XmlNode *templatesXml);

    //read a fixed template
    void _readTemplate(std::string formula);

    double _getFaultCoverage(Assertion &a);

    void _makeCandidatePropositions(ConeOfInfluence &cone);

    static void _makeCandidatePropositions(List<Proposition> &propositions,
                                           std::vector<size_t> chainOfNexts,
                                           Prop2DProps &candidatePropositions);

    void _selectDCVariables(const Template &antecedent, Proposition &consequent,
                            size_t offset, DecTreeVariables &dcVariables);

    bool _makeImply(const Template &templ, Proposition *proposition,
                    List<Assertion> &assertions);

    void _finalizeAntecedent(Assertion &assertion, const Template &antecedent,
                             const set<Proposition *> &props);
    //----------------------------------------------------------------------------
};

} // namespace ateam
