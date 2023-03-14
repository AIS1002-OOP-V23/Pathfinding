
#ifndef PATHFINDING_GAMEMAP_HPP
#define PATHFINDING_GAMEMAP_HPP

#include "pathfinding/TileBasedMap.hpp"

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class GameMap : public TileBasedMap {

public:
    explicit GameMap(std::vector<std::string> data) : data_(std::move(data)) {

        height_ = static_cast<int>(this->data_.size());

        // check that width is consistent
        unsigned width = data_[0].size();
        for (int i = 1; i < data_.size(); i++) {
            if (data_[i].size() != width) {
                throw std::runtime_error("Input breadth mismatch!");
            }
        }
        width_ = width;
    }

    [[nodiscard]] unsigned int width() const override {
        return width_;
    }

    [[nodiscard]] unsigned int height() const override {
        return height_;
    }

    [[nodiscard]] char get(int x, int y) const {
        return data_[y][x];
    }

    [[nodiscard]] bool blocked(const Coordinate &v) const override {
        char c = get(v.x, v.y);
        bool blocked = (c == '0');
        return blocked;
    }

    float getCost(const Coordinate &start, const Coordinate &target) override {
        return 1;
    }

    [[nodiscard]] std::vector<std::string> data() const {
        return data_;
    }

private:
    unsigned int width_, height_;
    std::vector<std::string> data_;
};

#endif//PATHFINDING_GAMEMAP_HPP
