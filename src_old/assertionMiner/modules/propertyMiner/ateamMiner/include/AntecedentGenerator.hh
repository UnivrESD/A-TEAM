#pragma once

#include "oden/List.hh"
#include "oden/classes/atom/Atom.hh"
#include "oden/classes/expression/Expression.hh"
#include "supportTypes.hh"

#include <list>
#include <set>

using namespace std;
using namespace oden;

namespace ateam {

/// @brief AntecedentGenerator
///
/// This class implements a search algorithm based on a decision tree.
/// Given a goal, which is represented by a proposition, the algorihtm generates
/// sets of constraints. When a constraint is satisfied, then the goal has
/// value 1.
///

class AntecedentGenerator {
  public:
    /// @brief Constructor.
    AntecedentGenerator();

    /// @brief Destructor.
    ~AntecedentGenerator() = default;

    /// @brief Copy constructor.
    /// @param other The other variable to be copied.
    AntecedentGenerator(const AntecedentGenerator &other) = delete;

    /// @brief Assignment operator
    /// @param other The other variable to be copied.
    AntecedentGenerator &operator=(const AntecedentGenerator &other) = delete;

    /// @brief maxPropositions defines the maximum number of propositions in a
    /// generated antecedent
    size_t maxPropositions;

    /// @brief saveOffset defines if
    bool saveOffset;

    /// the algorithm's result:
    set<set<Proposition *>> onSets;
    set<set<Proposition *>> offSets;

    /// @brief makeAntecedents
    /// @param dcVariables a set of Variables
    /// @paran posAndNeg a flag ...
    /// @return ....
    TraceInfo &makeAntecedents(DecTreeVariables &dcVariables,
                               TraceInfo &traceInfo);

  private:
    TraceInfo *_traceInfo;

    // the consequent's entropy
    double _entropyGoal;

    void _runDecisionTree(list<size_t> &unusedVars,
                          DecTreeVariables &dcVariables,
                          PropositionAnd *antecedent);

    void _store(PropositionAnd &antecedent, bool value);

    void _simplify(PropositionAnd &antecedent, bool value,
                   List<PropositionAnd> &shorterProps);

    void _getCoverage(PropositionAnd &proposition, bool value);
};

} // namespace ateam
