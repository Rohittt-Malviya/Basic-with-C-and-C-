#pragma once

#include "Types.hpp"

#include <string>

namespace dsa {

class NameGenerator {
  public:
    std::string slugFor(const DetectionResult &result) const;
};

} // namespace dsa
