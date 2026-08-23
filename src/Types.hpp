#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace dsa {

struct ScanConfig {
    std::filesystem::path root;
    std::vector<std::string> extensions;
    std::vector<std::string> ignoredDirectories;
};

struct CliOptions {
    bool dryRun = false;
    bool analyzeOnly = false;
    bool copyOnly = false;
    std::filesystem::path root;
};

struct SourceFile {
    std::filesystem::path absolutePath;
    std::filesystem::path relativePath;
    std::string extension;
    std::string language;
    std::string content;
};

struct DetectionResult {
    SourceFile file;
    std::string conceptSlug;
    std::string conceptTitle;
    std::string category;
    double confidence = 0.0;
    std::string conceptSummary;
    std::string howItWorks;
    std::string complexityTime;
    std::string complexitySpace;
    std::optional<std::string> mermaid;
    std::vector<std::string> interviewTests;
    std::vector<std::string> edgeCases;
    std::vector<std::string> followUps;
    std::vector<std::string> improvements;
    bool optimizationComparisonUseful = false;
    bool lowConfidence = false;
};

struct MovePlan {
    std::filesystem::path source;
    std::filesystem::path destination;
    std::string conceptSlug;
};

} // namespace dsa
