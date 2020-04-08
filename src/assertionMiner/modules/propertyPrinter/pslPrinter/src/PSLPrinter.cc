#include "PSLPrinter.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/propositionUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"

#include <iostream>
#include <spot/tl/print.hh>
#include <sstream>

using namespace std;
using namespace oden;

namespace pslPrinter {

PSLPrinter::PSLPrinter(XmlNode *data) : PropertyPrinter(data), _pslVisitor() {

  XmlNode *pslPrinterXml = data->first_node("generateChecker");
  if (pslPrinterXml == nullptr)
    messageError("The xml node 'generateChecker' has not been found");

  std::string value = getAttributeValue(pslPrinterXml, "value");
  if (value == "Yes") {
    _generateChecker = true;
    _checkerName = getAttributeValue(pslPrinterXml, "name");
  }
}

void PSLPrinter::print(ConeOfInfluence &cone) {

  if (_generateChecker) {

    stringstream ss;
    int maxID = 0;

    std::string moduleNameUpperCase = _checkerName;
    std::transform(moduleNameUpperCase.begin(), moduleNameUpperCase.end(),
                   moduleNameUpperCase.begin(), ::toupper);
    ss << "\n\n`define " << moduleNameUpperCase << " path_to_module\n";
    ss << "checker " << _checkerName << "_checker(";
    ss<<cone._clk;

    assert(cone.usedVariables.size()>0);

    for(size_t i=0;i<cone.usedVariables.size();i++){
      ss <<", " <<cone.usedVariables[i];
    }

    ss << ")";
    ss << ";\n";
    ss << "\tclocking clk_" << cone.name << " @(posedge " << cone._clk
       << ");\n\n";

    for (Assertion *assertion : cone.assertions) {
      ss << "\t\tproperty p" << assertion->id << ";\n\t\t  ";
//      _printer(*assertion, assertion->templ, ss);
        ss<< oden::prop2String(*assertion->antecedent);
        ss<<" |-> ";
        ss<< oden::prop2String(*assertion->consequent);
        ss<<"\n";
      ss << "\n\t\tendproperty\n\n";
      maxID = std::max(maxID, assertion->id);
    }
    ss << "\tendclocking\n\n";

    for (int i = 0; i <= maxID; i++) {
      ss << "\tp"<<i<<": assert property ("
         << "clk_" << cone.name << ".p" << i << ");\n";
    }

    ss << "endchecker: " << _checkerName << "_checker\n\n";
    ss << "bind `" << moduleNameUpperCase << " " << _checkerName<<"_checker "<<_checkerName
       << "_checker_instance(";
    ss<<"`" + moduleNameUpperCase + "." + cone._clk;
    for(size_t i=0;i<cone.usedVariables.size();i++){
      ss << ", `" + moduleNameUpperCase + "." + cone.usedVariables[i];
    }
    ss<<");";
    cout << ss.str() << endl;

  } else {
    stringstream ss;
    int maxID = 0;

    for (Assertion *assertion : cone.assertions) {
      ss << "\tproperty p" << assertion->id << ";\n\t  ";
//      _printer(*assertion, assertion->templ, ss);
        ss<< oden::prop2String(*assertion->antecedent);
        ss<<" |-> ";
        ss<< oden::prop2String(*assertion->consequent);
      ss << "\n\tendproperty\n\n";
      maxID = std::max(maxID, assertion->id);
    }
    cout << ss.str() << endl;
  }
}

void PSLPrinter::_printer(Assertion &assertion, Template templ,
                          stringstream &ss) {

  if (templ.is(spot::op::G)) {
    _printer(assertion, templ[0], ss);
    ss << ";";
    return;
  }

  if (templ.is(spot::op::X)) {
    unsigned int xCounter = 0;
    do {
      ++xCounter;
      templ = templ[0];
    } while (templ.is(spot::op::X));

    ss << "nexttime[" << xCounter << "](";
    _printer(assertion, templ, ss);
    ss << ")";
    return;
  }

  if (templ.is(spot::op::And)) {
    ss << "(";
    for (unsigned int fIndex = 0; fIndex < templ.size() - 1; ++fIndex) {
      Template atomicTempl = templ[fIndex];
      _printer(assertion, atomicTempl, ss);
      ss << " && ";
    }

    _printer(assertion, templ[templ.size() - 1], ss);
    ss << ")";
    return;
  }

  if (templ.is(spot::op::Implies)) {
    Template antecedent = templ[0];
    Template consequent = templ[1];

    _printer(assertion, antecedent, ss);
    ss << " |-> ";
    _printer(assertion, consequent, ss);

    return;
  }

  if (templ.is(spot::op::ap)) {
    Proposition *p = assertion.t2p[templ];
    messageErrorIf(p == nullptr,
                   "A proposition has not been set in the template!");

    p->acceptVisitor(_pslVisitor);
    ss << _pslVisitor.get();
    return;
  }

  spot::print_psl(std::cout, templ) << "\n";
  messageError("Unsupported operator!");
}

} // namespace pslPrinter
