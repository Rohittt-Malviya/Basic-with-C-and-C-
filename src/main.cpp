#include "CodeAnalyzer.hpp"
#include "FileScanner.hpp"
#include "RepositoryOrganizer.hpp"
#include "Types.hpp"

#include <filesystem>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {

void printHelp() {
    std::cout << "dsa-organizer - analyze and organize repositories by semantic code concepts\n\n";
    std::cout << "Usage:\n";
    std::cout << "  dsa-organizer [--dry-run] [--analyze-only] [--copy] <path>\n";
    std::cout << "  dsa-organizer --help\n\n";
    std::cout << "Options:\n";
    std::cout << "  --dry-run      Show planned file organization without modifying files\n";
    std::cout << "  --analyze-only Analyze and print concept detection only\n";
    std::cout << "  --copy         Organize by copy only (do not remove originals)\n";
    std::cout << "  --help         Show this help message\n";
}

std::optional<dsa::CliOptions> parseArgs(int argc, char **argv) {
    dsa::CliOptions options;
    options.root = ".";

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--help") {
            printHelp();
            return std::nullopt;
        }
        if (arg == "--dry-run") {
            options.dryRun = true;
            continue;
        }
        if (arg == "--analyze-only") {
            options.analyzeOnly = true;
            continue;
        }
        if (arg == "--copy") {
            options.copyOnly = true;
            continue;
        }

        options.root = arg;
    }

    options.root = std::filesystem::absolute(options.root);
    return options;
}

} // namespace

int main(int argc, char **argv) {
    const auto parsed = parseArgs(argc, argv);
    if (!parsed.has_value()) {
        return 0;
    }

    const dsa::CliOptions options = parsed.value();

    std::cout << "========================================\n";
    std::cout << "       Code Repository Analyzer\n";
    std::cout << "========================================\n\n";
    std::cout << "Scanning files...\n\n";

    const dsa::ScanConfig scanConfig{options.root,
                                     {".cpp", ".cc", ".cxx", ".hpp", ".h", ".java", ".py", ".js", ".ts", ".sql"},
                                     {".git", ".github", "node_modules", "build", "cmake-build-debug",
                                      "cmake-build-release", ".vscode", ".idea"}};

    dsa::FileScanner scanner;
    const auto files = scanner.scan(scanConfig);
    std::cout << "✓ " << files.size() << " source files detected\n\n";

    std::cout << "Analyzing...\n\n";
    dsa::CodeAnalyzer analyzer;
    const auto analysis = analyzer.analyze(options.root, files);

    std::cout << std::left << std::setw(42) << "File" << std::setw(32) << "Detected Concept" << "Confidence" << "\n";
    std::cout << std::string(90, '-') << "\n";

    for (const auto &entry : analysis) {
        const auto confidencePct = static_cast<int>(entry.confidence * 100.0);
        std::cout << std::left << std::setw(42) << entry.file.relativePath.string() << std::setw(32) << entry.conceptTitle
                  << (std::to_string(confidencePct) + "%");
        if (entry.lowConfidence) {
            std::cout << "  ⚠ Manual review required";
        }
        std::cout << "\n";
    }

    if (options.analyzeOnly) {
        std::cout << "\nAnalysis completed (no changes made).\n";
        return 0;
    }

    dsa::RepositoryOrganizer organizer;
    const auto plans = organizer.planMoves(options.root, analysis);

    std::cout << "\nOrganizing repository...\n";
    if (!organizer.execute(options, analysis, plans)) {
        std::cerr << "Organization failed.\n";
        return 1;
    }

    if (options.dryRun) {
        std::cout << "Dry run completed successfully.\n";
    } else {
        std::cout << "\nGenerating documentation...\n";
        std::cout << "✓ Concept READMEs generated\n";
        std::cout << "✓ Root README updated\n";
        std::cout << "\nCompleted successfully.\n";
    }

    return 0;
}
