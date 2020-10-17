#include "oden/modules/PropositionMiner.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {
namespace modules {

PropositionMiner::PropositionMiner(XmlNode *data) : configuration(nullptr) {
    if (data == nullptr)
        messageError("Invalid XML::Node object for PropositionMiner class");

    configuration = data;
}

} // namespace modules
} // namespace oden
