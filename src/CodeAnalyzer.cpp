#include "CodeAnalyzer.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

namespace dsa {

std::string CodeAnalyzer::languageFromExtension(const std::string &ext) const {
    if (ext == ".cpp" || ext == ".cc" || ext == ".cxx" || ext == ".h" || ext == ".hpp") {
        return "C++";
    }
    if (ext == ".java") {
        return "Java";
    }
    if (ext == ".py") {
        return "Python";
    }
    if (ext == ".js") {
        return "JavaScript";
    }
    if (ext == ".ts") {
        return "TypeScript";
    }
    if (ext == ".sql") {
        return "SQL";
    }
    return "Unknown";
}

std::vector<DetectionResult> CodeAnalyzer::analyze(const std::filesystem::path &root,
                                                   const std::vector<std::filesystem::path> &files) const {
    std::vector<DetectionResult> results;
    results.reserve(files.size());

    for (const auto &path : files) {
        std::ifstream in(path, std::ios::binary);
        if (!in) {
            continue;
        }
        std::ostringstream buffer;
        buffer << in.rdbuf();

        std::string ext = path.extension().string();
        std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

        SourceFile source;
        source.absolutePath = path;
        source.relativePath = std::filesystem::relative(path, root);
        source.extension = ext;
        source.language = languageFromExtension(ext);
        source.content = buffer.str();

        auto detected = detector_.detect(source);
        complexity_.enrich(detected);
        results.push_back(std::move(detected));
    }

    return results;
}

} // namespace dsa
