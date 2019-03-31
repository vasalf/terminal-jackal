#include "Chip.h"

using namespace NJackal;

Chip::Chip(Coordinate coord, ChipType type)
: old_coord(coord), coord(coord), type(type)
{
    cell_data = NULL;
}

Coordinate Chip::get_old_coord() const
{
    return old_coord;
}

Coordinate Chip::get_coord() const
{
    return coord;
}

void Chip::set_coord(Coordinate coord)
{
    this->old_coord = this->coord;
    this->coord = coord;
}

ChipType Chip::get_type() const
{
    return type;
}