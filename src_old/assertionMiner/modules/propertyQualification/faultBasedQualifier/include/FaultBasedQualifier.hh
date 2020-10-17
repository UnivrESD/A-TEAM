//
// Created by danes on 11/09/2019.
//
#pragma once
#include "oden/modules/PropertyQualifier.hh"

using namespace oden;

namespace faultBasedQualifier {

/// @brief BooleanVariables declaration.
///
/// This class defines two propositions for each boolean variable
/// in the cone of influence. (boolean a -> {a, !a})
///

class FaultBasedQualifier : public modules::PropertyQualifier {

  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing miner's parameters
    explicit FaultBasedQualifier(XmlNode *data);

    /// @brief Destructor.
    ~FaultBasedQualifier() override = default;

    /// @brief This methods applies the faultList attribute of the mined
    /// assertions to prune them without decreasing the overall fault coverage.
    /// @param cone A cone of influence
    void qualify(ConeOfInfluence &cones) override;
};

} // namespace faultBasedQualifier
