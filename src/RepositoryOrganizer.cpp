#include "RepositoryOrganizer.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>

namespace dsa {

std::vector<MovePlan> RepositoryOrganizer::planMoves(const std::filesystem::path &root,
                                                     const std::vector<DetectionResult> &results) const {
    std::unordered_map<std::string, int> counters;
    std::vector<MovePlan> plans;
    plans.reserve(results.size());

    for (const auto &result : results) {
        auto &counter = counters[result.conceptSlug];
        ++counter;

        const auto folder = root / result.conceptSlug;
        std::string baseName = "solution";
        if (counter > 1) {
            baseName += "-" + std::to_string(counter);
        }

        auto destination = folder / (baseName + result.file.extension);
        int suffix = counter;
        while (std::filesystem::exists(destination)) {
            ++suffix;
            destination = folder / ("solution-" + std::to_string(suffix) + result.file.extension);
        }

        plans.push_back(MovePlan{result.file.absolutePath, destination, result.conceptSlug});
    }

    return plans;
}

bool RepositoryOrganizer::verifyCopy(const std::filesystem::path &source, const std::filesystem::path &destination) const {
    if (!std::filesystem::exists(source) || !std::filesystem::exists(destination)) {
        return false;
    }

    if (std::filesystem::file_size(source) != std::filesystem::file_size(destination)) {
        return false;
    }

    return true;
}

bool RepositoryOrganizer::execute(const CliOptions &options, const std::vector<DetectionResult> &results,
                                  const std::vector<MovePlan> &plans) const {
    std::map<std::string, std::vector<DetectionResult>> grouped;
    std::map<std::string, std::string> slugToTitle;

    for (const auto &result : results) {
        grouped[result.conceptSlug].push_back(result);
        slugToTitle[result.conceptSlug] = result.conceptTitle;
    }

    if (options.dryRun) {
        std::cout << "\nDRY RUN\n\n";
        for (const auto &plan : plans) {
            std::cout << std::filesystem::relative(plan.source, options.root).string() << "\n";
            std::cout << "    ↓\n";
            std::cout << std::filesystem::relative(plan.destination, options.root).string() << "\n\n";
        }
        return true;
    }

    for (const auto &plan : plans) {
        std::filesystem::create_directories(plan.destination.parent_path());
        std::filesystem::copy_file(plan.source, plan.destination, std::filesystem::copy_options::none);
        if (!verifyCopy(plan.source, plan.destination)) {
            std::cerr << "Copy verification failed for: " << plan.source << "\n";
            return false;
        }

        if (!options.copyOnly) {
            std::filesystem::remove(plan.source);
        }
    }

    for (const auto &[slug, items] : grouped) {
        auto readmePath = options.root / slug / "README.md";
        std::ofstream out(readmePath, std::ios::binary);
        out << markdown_.conceptReadme(slugToTitle[slug], items);
    }

    const auto stats = stats_.build(results);
    std::ofstream rootReadme(options.root / "README.md", std::ios::binary);
    rootReadme << markdown_.rootReadme(results, stats, slugToTitle);

    return true;
}

} // namespace dsa
