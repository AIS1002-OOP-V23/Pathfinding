cmake_minimum_required(VERSION 3.15)
project(pathfinding)

set(CMAKE_CXX_STANDARD 17)

set(includeDir "${CMAKE_SOURCE_DIR}/include")
add_library(pathfinding INTERFACE
        "${includeDir}/pathfinding/Coordinate.hpp"
        "${includeDir}/pathfinding/Heuristic.hpp"
        "${includeDir}/pathfinding/Path.hpp"
        "${includeDir}/pathfinding/PathFinder.hpp"
        "${includeDir}/pathfinding/TileBasedMap.hpp"

        "${includeDir}/pathfinding/heuristics/ClosestHeuristic.hpp"
        "${includeDir}/pathfinding/heuristics/ClosestSquaredHeuristic.hpp"
        "${includeDir}/pathfinding/heuristics/ManhattanHeuristic.hpp"

        "${includeDir}/pathfinding/astar/AStar.hpp"
        )
target_include_directories(pathfinding INTERFACE "${includeDir}")

add_subdirectory(examples)

# testing
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
