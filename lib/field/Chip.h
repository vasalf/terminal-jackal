#pragma once

#include "Coordinate.h"

namespace NJackal {

enum ChipType {SHIP, PIRATE};

class Chip {
private:
    ChipType type;

    Coordinate old_coord;
    Coordinate coord;

public:
    Chip() = delete;
    Chip(Coordinate coord, ChipType type);
    Chip(const Chip &other) = default;

    Coordinate get_old_coord() const;
    Coordinate get_coord() const;
    void set_coord(Coordinate coord);

    ChipType get_type() const;
};

}
