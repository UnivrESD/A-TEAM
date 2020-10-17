#pragma once
#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"
#include <list>

using namespace std;
using namespace oden;

namespace ateam {

/// @brief FaultChecker declaration.
/// This class reads ....
class FaultChecker {
  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing the root tag of a xml file
    explicit FaultChecker(XmlNode *xmlNode);

    /// @brief Destructor.
    ~FaultChecker();

    /// @brief Returns the current fault coverage.
    /// @return the reached fault coverage.
    double getCoverage();

    /// @brief Checks what faults can be covered by the given assertion.
    /// This method can increase the fault coverage.
    /// @param assertion an assertion.
    /// @param faults the list of faults caught by the given assertion.
    void check(Assertion &assertion);

  private:
    // The repository of faulty traces
    TraceRepository *_faultyTraces;

    // The number of faulty traces covered by at least one asseriton
    int _covTraces;

    // bitmap. Each bit represents a faulty trace. bit at position i-th ->
    // no assertion can catch the fault in the ith trace. 1 otherwise.
    unsigned *_coverageMap;
};

} // namespace ateam
