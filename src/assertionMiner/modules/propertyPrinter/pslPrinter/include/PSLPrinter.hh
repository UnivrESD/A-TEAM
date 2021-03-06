#pragma once

#include "PSLPropositionPrinter.hh"
#include "oden/modules/PropertyPrinter.hh"
#include "oden/types.hh"

#include <string>
#include <algorithm>

using namespace oden;

namespace pslPrinter {

class PSLPrinter : public modules::PropertyPrinter {

  public:
    explicit PSLPrinter(XmlNode *data);
    ~PSLPrinter() override = default;

    void print(ConeOfInfluence &cone) override;

  private:
    PSLPropositionPrinter _pslVisitor;
    void _printer(oden::Assertion &assertion, oden::Template templ,
                  std::stringstream &ss);
    bool _generateChecker=false;
    std::string _checkerName="";
};

} // namespace pslPrinter
