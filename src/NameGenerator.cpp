#include "NameGenerator.hpp"

namespace dsa {

std::string NameGenerator::slugFor(const DetectionResult &result) const { return result.conceptSlug; }

} // namespace dsa
