#pragma once

#include <list>
#include <map>
#include <string>

#include "oden/classes/atom/Atom.hh"

//==== external libraries ===================================================
#include "oden/odenUtils/rapidxml/rapidxml_utils.hh" // RAPIDXML headers
#include "spot/tl/formula.hh"                        // SPOT library
//---------------------------------------------------------------------------

namespace oden {

using Template    = spot::formula;
using XmlNode     = rapidxml::xml_node<>;
using XmlNodeList = std::vector<XmlNode *>;

/// @brief Assertion struct represents a temporal assertion.
struct Assertion {
    /// @brief Assertion identifier
    int id;
    /// @brief Assertion template.
    Proposition *antecedent;
    Proposition *consequent;

    Template templ;
    std::map<Template,Proposition*> t2p;
    std::vector<size_t> faultList; 

    Assertion();
    /// @brief Copy constructor.
    Assertion(const Assertion &other);
    /// @brief Destructor.
    virtual ~Assertion();
    /// @brief Assign operator.
    Assertion &operator=(const Assertion &other) = delete;
};

} // namespace oden
