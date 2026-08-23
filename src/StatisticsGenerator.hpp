#pragma once

#include "Types.hpp"

#include <map>
#include <vector>

namespace dsa {

struct RepositoryStats {
    int totalImplementations = 0;
    std::map<std::string, int> languageCounts;
    std::map<std::string, int> categoryCounts;
    std::vector<std::string> concepts;
};

class StatisticsGenerator {
  public:
    RepositoryStats build(const std::vector<DetectionResult> &results) const;
};

} // namespace dsa
