
#include "GameMap.hpp"

#include "pathfinding/astar/AStar.hpp"
#include "pathfinding/Coordinate.hpp"
#include "pathfinding/TileBasedMap.hpp"
#include "pathfinding/heuristics/ClosestHeuristic.hpp"

#include <iostream>
#include <vector>

void printPath(std::vector<std::string> data, const Path &p) {

    auto &start = p.start();
    auto &target = p.target();
    data[start.y][start.x] = 'S';
    data[target.y][target.x] = 'T';

    size_t length = p.length();
    for (int i = 1; i < length - 1; i++) {
        Coordinate c = p[i];
        data[c.y][c.x] = 'x';
    }

    for (auto &line: data) {
        std::cout << line << "\n";
    }
    std::cout << "Path length=" << length << "\n\n";
}

int main() {

    std::vector<std::string> data{"10011111",
                                  "11011111",
                                  "01111011",
                                  "11111110"};

    std::unique_ptr<TileBasedMap> map = std::make_unique<GameMap>(data);

    Coordinate start{0, 0};
    Coordinate target{3, 0};

    AStar a(std::move(map), std::make_unique<ClosestHeuristic>());

    {
        a.setAllowDiagMovement(true);

        auto path = a.findPath(start, target);

        if (path) {

            printPath(data, *path);
        } else {

            std::cerr << "Unable to compute path between " << start << " and " << target << std::endl;
        }
    }

    {
        a.setAllowDiagMovement(false);

        auto path = a.findPath(start, target);

        if (path) {

            printPath(data, *path);
        } else {

            std::cerr << "Unable to compute path between " << start << " and " << target << std::endl;
        }
    }
}
