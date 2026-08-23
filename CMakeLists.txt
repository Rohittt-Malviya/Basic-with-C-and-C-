cmake_minimum_required(VERSION 3.16)
project(dsa_organizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dsa-organizer
    src/main.cpp
    src/FileScanner.cpp
    src/ConceptDetector.cpp
    src/CodeAnalyzer.cpp
    src/NameGenerator.cpp
    src/ComplexityAnalyzer.cpp
    src/MarkdownGenerator.cpp
    src/RepositoryOrganizer.cpp
    src/StatisticsGenerator.cpp
)

target_include_directories(dsa-organizer PRIVATE src)
