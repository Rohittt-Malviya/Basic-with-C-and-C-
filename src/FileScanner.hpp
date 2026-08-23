#pragma once

#include "Types.hpp"

#include <filesystem>
#include <vector>

namespace dsa {

class FileScanner {
  public:
    std::vector<std::filesystem::path> scan(const ScanConfig &config) const;
};

} // namespace dsa
