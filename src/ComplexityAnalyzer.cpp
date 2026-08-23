#include "ComplexityAnalyzer.hpp"

#include <string>

namespace dsa {

void ComplexityAnalyzer::enrich(DetectionResult &result) const {
    if (result.complexityTime != "Not confidently derivable") {
        return;
    }

    const std::string &code = result.file.content;
    const bool hasNestedLoop = code.find("for") != std::string::npos &&
                               (code.find("for", code.find("for") + 1) != std::string::npos ||
                                code.find("while", code.find("for") + 1) != std::string::npos);

    if (hasNestedLoop) {
        result.complexityTime = "Likely O(n^2) from nested iteration";
        result.complexitySpace = "Likely O(1) auxiliary";
    } else if (code.find("for") != std::string::npos || code.find("while") != std::string::npos) {
        result.complexityTime = "Likely O(n) from single-pass iteration";
        result.complexitySpace = "Likely O(1) auxiliary";
    }
}

} // namespace dsa
