#include "oden/classes/ConeOfInfluence.hh"

namespace oden {

ConeOfInfluence::ConeOfInfluence(const std::string &n)
    : inPropositions(), outPropositions(), inoutPropositions(), assertions(),
      name(n) {
    // ntd
}
ConeOfInfluence::~ConeOfInfluence(){

}

} // namespace oden
