#pragma once

#include "MarkdownGenerator.hpp"
#include "StatisticsGenerator.hpp"
#include "Types.hpp"

#include <filesystem>
#include <map>
#include <vector>

namespace dsa {

class RepositoryOrganizer {
  public:
    std::vector<MovePlan> planMoves(const std::filesystem::path &root, const std::vector<DetectionResult> &results) const;
    bool execute(const CliOptions &options, const std::vector<DetectionResult> &results,
                 const std::vector<MovePlan> &plans) const;

  private:
    bool verifyCopy(const std::filesystem::path &source, const std::filesystem::path &destination) const;
    MarkdownGenerator markdown_;
    StatisticsGenerator stats_;
};

} // namespace dsa
