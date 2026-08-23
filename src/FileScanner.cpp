#include "FileScanner.hpp"

#include <algorithm>
#include <unordered_set>

namespace dsa {

std::vector<std::filesystem::path> FileScanner::scan(const ScanConfig &config) const {
    std::unordered_set<std::string> allowed;
    for (const auto &ext : config.extensions) {
        allowed.insert(ext);
    }

    std::unordered_set<std::string> ignored;
    for (const auto &dir : config.ignoredDirectories) {
        ignored.insert(dir);
    }

    std::vector<std::filesystem::path> results;
    if (!std::filesystem::exists(config.root)) {
        return results;
    }

    for (std::filesystem::recursive_directory_iterator it(config.root), end; it != end; ++it) {
        const auto &entry = *it;
        if (entry.is_directory()) {
            const auto name = entry.path().filename().string();
            if (ignored.count(name)) {
                it.disable_recursion_pending();
            }
            continue;
        }

        if (!entry.is_regular_file()) {
            continue;
        }

        auto ext = entry.path().extension().string();
        std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        if (allowed.count(ext)) {
            results.push_back(entry.path());
        }
    }

    std::sort(results.begin(), results.end());
    return results;
}

} // namespace dsa
