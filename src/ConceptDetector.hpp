#pragma once

#include "Types.hpp"

#include <string>

namespace dsa {

class ConceptDetector {
  public:
    DetectionResult detect(const SourceFile &file) const;

  private:
    static std::string toLower(std::string value);
    static int countSignals(const std::string &text, const std::vector<std::string> &signals);
};

} // namespace dsa
