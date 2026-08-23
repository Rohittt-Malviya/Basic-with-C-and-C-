#include "MarkdownGenerator.hpp"

#include <algorithm>
#include <sstream>
#include <vector>

namespace dsa {

std::string MarkdownGenerator::escapePipe(std::string text) {
    std::replace(text.begin(), text.end(), '|', '/');
    return text;
}

std::string MarkdownGenerator::conceptReadme(const std::string &conceptTitle,
                                             const std::vector<DetectionResult> &items) const {
    std::ostringstream out;
    const auto &seed = items.front();

    out << "# " << conceptTitle << "\n\n";
    out << "> " << seed.conceptSummary << "\n\n";
    out << "## 🧩 What This Code Does\n\n";
    out << "This folder groups " << items.size()
        << " implementation(s) detected in the repository that semantically match this concept.\n\n";

    out << "## 💡 Concept\n\n";
    out << seed.conceptSummary << "\n\n";

    out << "## 🧠 How It Works\n\n";
    out << seed.howItWorks << "\n\n";

    if (seed.mermaid.has_value()) {
        out << "## 📊 Visual Explanation\n\n```mermaid\n" << seed.mermaid.value() << "\n```\n\n";
    }

    out << "## ⏱ Complexity Analysis\n\n";
    out << "| Complexity | Value |\n";
    out << "| ---------- | ----- |\n";
    out << "| Time | " << seed.complexityTime << " |\n";
    out << "| Space | " << seed.complexitySpace << " |\n\n";

    if (seed.optimizationComparisonUseful) {
        out << "## 🐢 Brute Force\n\n";
        out << "A straightforward baseline would typically recompute or scan more states than necessary.\n\n";
        out << "## 🚀 Current Approach\n\n";
        out << "This implementation applies a targeted algorithmic strategy to reduce unnecessary work.\n\n";
        out << "## ⚖️ Trade-Off\n\n";
        out << "The optimized approach improves runtime while potentially requiring stronger assumptions or extra state.\n\n";
    }

    out << "## 🎤 Interview Perspective\n\n";
    out << "### What This Concept Tests\n\n";
    for (const auto &line : seed.interviewTests) {
        out << "- " << line << "\n";
    }
    out << "\n### Common Edge Cases\n\n";
    for (const auto &line : seed.edgeCases) {
        out << "- " << line << "\n";
    }
    out << "\n### Possible Follow-Ups\n\n";
    for (const auto &line : seed.followUps) {
        out << "- " << line << "\n";
    }
    out << "\n";

    out << "## 💻 Solution\n\n";
    for (std::size_t i = 0; i < items.size(); ++i) {
        const auto suffix = (i == 0) ? "" : ("-" + std::to_string(i + 1));
        out << "- <a href=\"./solution" << suffix << items[i].file.extension << "\">View " << items[i].file.language
            << " Solution</a>\n";
    }
    out << "\n";

    bool hasImprovement = false;
    for (const auto &item : items) {
        if (!item.improvements.empty()) {
            hasImprovement = true;
            break;
        }
    }

    if (hasImprovement) {
        out << "## 🔧 Potential Improvements\n\n";
        for (const auto &item : items) {
            for (const auto &improvement : item.improvements) {
                out << "- " << improvement << "\n";
            }
        }
        out << "\n";
    }

    return out.str();
}

std::string MarkdownGenerator::rootReadme(const std::vector<DetectionResult> &results, const RepositoryStats &stats,
                                          const std::map<std::string, std::string> &slugToTitle) const {
    std::ostringstream out;

    out << "# 🧠 Algorithms & Problem-Solving Portfolio\n\n";
    out << "> A structured collection of algorithms, data structures, and programming solutions with clear technical explanations and complexity analysis.\n\n";
    out << "---\n\n";

    out << "## 🚀 Concepts Covered\n\n";
    for (const auto &title : stats.concepts) {
        out << "- " << title << "\n";
    }
    out << "\n";

    out << "## 📈 Repository Statistics\n\n";
    out << "| Metric | Count |\n";
    out << "| ----- | ----: |\n";
    out << "| Total Implementations | " << stats.totalImplementations << " |\n";

    const std::vector<std::string> languageOrder{"C++", "Java", "Python", "JavaScript", "TypeScript", "SQL"};
    for (const auto &lang : languageOrder) {
        auto it = stats.languageCounts.find(lang);
        out << "| " << lang << " | " << (it == stats.languageCounts.end() ? 0 : it->second) << " |\n";
    }
    out << "\n";

    out << "| Concept | Count |\n";
    out << "| ------- | ----: |\n";
    for (const auto &entry : stats.categoryCounts) {
        out << "| " << escapePipe(entry.first) << " | " << entry.second << " |\n";
    }
    out << "\n";

    out << "## 🗂 Implementation Index\n\n";
    out << "| # | Implementation | Concept | Language | Documentation |\n";
    out << "| - | -------------- | ------- | -------- | ------------- |\n";

    int idx = 1;
    for (const auto &[slug, title] : slugToTitle) {
        auto it = std::find_if(results.begin(), results.end(), [&](const DetectionResult &r) { return r.conceptSlug == slug; });
        if (it == results.end()) {
            continue;
        }

        out << "| " << idx++ << " | " << escapePipe(title) << " | " << escapePipe(it->category) << " | "
            << escapePipe(it->file.language) << " | [View](./" << slug << "/) |\n";
    }
    out << "\n";

    out << "## 🧭 Learning Map\n\n";
    out << "```mermaid\n";
    out << "flowchart TD\n";

    const std::vector<std::pair<std::string, std::string>> chain = {
        {"Arrays", "Arrays & Strings"},       {"Searching", "Searching"},
        {"Sorting", "Sorting"},               {"Hashing", "Hashing"},
        {"Linked Lists", "Linked Lists"},     {"Trees", "Trees"},
        {"Graphs", "Graphs"},                 {"Dynamic Programming", "Dynamic Programming"},
        {"Recursion", "Recursion"},           {"General", "General Programming"},
        {"Systems", "Systems"},
    };

    std::vector<std::pair<std::string, std::string>> present;
    for (const auto &node : chain) {
        if (stats.categoryCounts.count(node.first)) {
            present.push_back(node);
        }
    }

    for (std::size_t i = 0; i < present.size(); ++i) {
        out << "    N" << i << "[" << present[i].second << "]\n";
    }
    for (std::size_t i = 0; i + 1 < present.size(); ++i) {
        out << "    N" << i << " --> N" << (i + 1) << "\n";
    }
    out << "```\n";

    return out.str();
}

} // namespace dsa
