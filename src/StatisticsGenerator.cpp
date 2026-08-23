#include "StatisticsGenerator.hpp"

#include <set>

namespace dsa {

RepositoryStats StatisticsGenerator::build(const std::vector<DetectionResult> &results) const {
    RepositoryStats stats;
    stats.totalImplementations = static_cast<int>(results.size());

    std::set<std::string> conceptSet;
    for (const auto &result : results) {
        stats.languageCounts[result.file.language]++;
        stats.categoryCounts[result.category]++;
        conceptSet.insert(result.conceptTitle);
    }

    stats.concepts.assign(conceptSet.begin(), conceptSet.end());
    return stats;
}

} // namespace dsa
