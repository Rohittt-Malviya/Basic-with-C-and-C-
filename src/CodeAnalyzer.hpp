#pragma once

#include "ComplexityAnalyzer.hpp"
#include "ConceptDetector.hpp"
#include "Types.hpp"

#include <filesystem>
#include <vector>

namespace dsa {

class CodeAnalyzer {
  public:
    std::vector<DetectionResult> analyze(const std::filesystem::path &root,
                                         const std::vector<std::filesystem::path> &files) const;

  private:
    std::string languageFromExtension(const std::string &ext) const;
    ConceptDetector detector_;
    ComplexityAnalyzer complexity_;
};

} // namespace dsa
