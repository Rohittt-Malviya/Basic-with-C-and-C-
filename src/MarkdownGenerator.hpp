#pragma once

#include "StatisticsGenerator.hpp"
#include "Types.hpp"

#include <map>
#include <string>
#include <vector>

namespace dsa {

class MarkdownGenerator {
  public:
    std::string conceptReadme(const std::string &conceptTitle, const std::vector<DetectionResult> &items) const;
    std::string rootReadme(const std::vector<DetectionResult> &results, const RepositoryStats &stats,
                           const std::map<std::string, std::string> &slugToTitle) const;

  private:
    static std::string escapePipe(std::string text);
};

} // namespace dsa
