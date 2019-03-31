#include "Team.h"

using namespace NJackal;

using std::vector;

Team::Team(Coordinate coord)
: ship(coord, SHIP)
{
    for (size_t i = 0; i < 3; i++)
        pirates.push_back(Chip(coord, PIRATE));
}

Chip Team::get_ship(size_t num) const
{
    return ship;
}

Chip& Team::ship(size_t num)
{
    return ship;
}

vector<size_t> get_pirates_nums();
{
    vector<size_t> nums;
    for (size_t num = 0; num < MAX_PIRATES_COUNT; num++)
        if (pirates.count(num))
            nums.push_back(num);
    return nums;
}

Chip Team::get_pirate(size_t num) const
{
    return pirates[num];
}

Chip& Team::pirate(size_t num)
{
    return pirates[num];
}