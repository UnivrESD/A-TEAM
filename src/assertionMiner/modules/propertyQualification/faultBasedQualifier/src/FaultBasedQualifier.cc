#include "FaultBasedQualifier.hh"
#include "oden/odenUtils/applicationUtils.hh"

#ifdef Z3_FOUND
#include "z3++.h"
#include <map>
#include <sstream>
#endif

using namespace std;

namespace faultBasedQualifier {

FaultBasedQualifier::FaultBasedQualifier(XmlNode *data)
    : modules::PropertyQualifier(data) {
    // ntd
}

void FaultBasedQualifier::qualify(ConeOfInfluence &cones) {
    List<Assertion> &assertions = cones.assertions;

     if (assertions.size() <= 1)
         return;

#ifdef Z3_FOUND
    // for each fault f, get the list of assertion-IDs covering f
    map<size_t, list<int>> fault2asserts;
    for (Assertion *assertion : assertions)
        for (size_t faultId : assertion->faultList)
            fault2asserts[faultId].push_back(assertion->id);

    // init optimizer
    z3::context c;
    z3::optimize opt(c);
    z3::params p(c);
    opt.set(p);

    // for each assertion i, create a new integer variable x_i having a value in
    // {1, 0}. If x_i is 1, then the assertion i is taken, otherwise it is
    // discarded.
    map<int, z3::expr> assertId2var;
    for (Assertion *assertion : assertions) {
        // make the x_i variable
        stringstream x_name;
        x_name << "x_" << assertion->id;
        z3::expr var = c.int_const(x_name.str().c_str());
        // add the constraint x_i in {1, 0}
        opt.add(var >= 0 && var <= 1);
        // map the assertion ith to the x_i variable
        assertId2var.insert({assertion->id, var});
    }

    // for each fault f, add the constraint x_i + x_j + ... + x_z >= 1 to MILP,
    // where the variable x_i, x_j ..., x_z represent the assertions
    // i, j, ..., z covering f.
    for (auto &kv : fault2asserts) {
        // get the list of assertIDs covering f
        list<int> &assertIDs = kv.second;

        // create the expression x_i + x_j + ... + x_z
        z3::expr_vector operands(c);
        for (int assertID : assertIDs)
            operands.push_back(assertId2var.at(assertID));

        // make x_i + x_j + ... + x_z be >= 1, namely at least an assertion
        // must be taken to cover the fault f
        opt.add((z3::sum(operands) >= 1));
    }

    // create the goal formula to be minimized : x_0 + x_1 + ... + x_n
    z3::expr_vector goal(c);
    for (auto &kv : assertId2var)
        goal.push_back(kv.second);

    // perform the minimization
    messageInfo("Performing property qualification based on fault coverage...");
    messageInfo("Initial number of assertions: " +
                to_string(assertions.size()));
    opt.minimize(z3::sum(goal));

    messageErrorIf(z3::sat != opt.check(), "Something went wrong...");

    z3::model model = opt.get_model();

    auto iter = assertions.begin();
    while (iter != assertions.end()) {
        Assertion *assertion = *iter;
        z3::func_decl dec    = assertId2var.at(assertion->id).decl();

        unsigned int x_i_value = model.get_const_interp(dec).get_numeral_uint();
        if (x_i_value == 0)
            iter = assertions.erase(iter);
        else
            ++iter;
    }

    messageInfo("Final number of assertions: " + to_string(assertions.size()));

#else
    messageInfo("Z3 solver was not found!");
    messageInfo("Fault Based qualifier ignored...");
#endif
}

}
