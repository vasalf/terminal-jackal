#pragma once

#include "Coordinate.h"
#include "Chip.h"

#include <map>

namespace NJackal {

class Team {
private:
    static const MAX_PIRATES_COUNT = 3;

    Chip ship;
    std::map<size_t, Chip> pirates;

public:
    Team() = delete;
    Team(Coordinate coord);
    Team(const Team &other) = default;

    Chip get_ship(size_t num) const;
    Chip& ship(size_t num);

    std::vector<size_t> get_pirates_nums() const;
    Chip get_pirate(size_t num) const;
    Chip& pirate(size_t num);
};

}
