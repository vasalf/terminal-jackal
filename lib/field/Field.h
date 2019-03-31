#pragma once

#include "Utils.h"

#include "Coordinate.h"
#include "Chip.h"
#include "Team.h"

#include "cell/AbstractCell.h"
#include "cell/CellArrow.h"
#include "cell/CellBalloob.h"
#include "cell/CellCannibal.h"
#include "cell/CellCrocodile.h"
#include "cell/CellFortress.h"
#include "cell/CellGold.h"
#include "cell/CellGun.h"
#include "cell/CellHorse.h"
#include "cell/CellIce.h"
#include "cell/CellLand.h"
#include "cell/CellPlane.h"
#include "cell/CellRum.h"
#include "cell/CellTrap.h"
#include "cell/CellWater.h"
#include "cell/CellWhirligig.h"

#include "AbstractResolver.h"

#include <vector>

namespace NJackal {

enum GAME_STATE {PROCESSING, DRAW, WIN};

class Field {
private:
    static const size_t FIELD_WIDTH = 13;
    static const size_t FIELD_HEIGHT = 13;

    static const std::vector<Coordinate> TEAM_START_COORDINATES = { Coordinate(FIELD_WIDTH / 2,                0),
                                                                    Coordinate(              0, FIELD_HEIGHT / 2),
                                                                    Coordinate(FIELD_WIDTH / 2, FIELD_HEIGHT - 1),
                                                                    Coordinate(FIELD_WIDTH - 1, FIELD_HEIGHT / 2)};


    static const std::vector<Coordinate> FIELD_CORNER_COORDINATES = {   Coordinate(              0,                0),
                                                                        Coordinate(              0, FIELD_HEIGHT - 1),
                                                                        Coordinate(FIELD_WIDTH - 1, FIELD_HEIGHT - 1),
                                                                        Coordinate(FIELD_WIDTH - 1,                0)};

    static const std::vector<Coordinate> WATER_CORNER_COORDINATES = {   Coordinate(              1,                1),
                                                                        Coordinate(              1, FIELD_HEIGHT - 2),
                                                                        Coordinate(FIELD_WIDTH - 2, FIELD_HEIGHT - 2),
                                                                        Coordinate(FIELD_WIDTH - 2,                1)};

    static const size_t CELL_LAND_COUNT = 40;

    static const size_t CELL_ARROW_ONE_DIR_STRAIGHT_COUNT = 3;
    static const size_t CELL_ARROW_ONE_DIR_DIAGONAL_COUNT = 3;
    static const size_t CELL_ARROW_TWO_DIR_STRAIGHT_COUNT = 3;
    static const size_t CELL_ARROW_TWO_DIR_DIAGONAL_COUNT = 3;
    static const size_t CELL_ARROW_THREE_DIR_COUNT = 3;
    static const size_t CELL_ARROW_FOUR_DIR_STRAIGHT_COUNT = 3;
    static const size_t CELL_ARROW_FOUR_DIR_DIAGONAL_COUNT = 3;

    static const size_t CELL_HORSE_COUNT = 2;

    static const size_t CELL_RUM_COUNT = 4;

    static const size_t CELL_WHIRLIGIG_2_COUNT = 5;
    static const size_t CELL_WHIRLIGIG_3_COUNT = 4;
    static const size_t CELL_WHIRLIGIG_4_COUNT = 2;
    static const size_t CELL_WHIRLIGIG_5_COUNT = 1;

    static const size_t CELL_ICE_COUNT = 6;

    static const size_t CELL_TRAP_COUNT = 3;

    static const size_t CELL_CROCODILE_COUNT = 4;

    static const size_t CELL_CANNIBAL_COUNT = 1;

    static const size_t CELL_FORTRESS_COUNT = 2;
    static const size_t CELL_FORTRESS_ABORIGINE_COUNT = 1;

    static const size_t CELL_GOLD_1_COUNT = 5;
    static const size_t CELL_GOLD_2_COUNT = 5;
    static const size_t CELL_GOLD_3_COUNT = 3;
    static const size_t CELL_GOLD_4_COUNT = 2;
    static const size_t CELL_GOLD_5_COUNT = 1;
    
    static const size_t CELL_BALLOON_COUNT = 2;

    static const size_t CELL_PLANE_COUNT = 1;

    static const size_t CELL_GUN_COUNT = 2;

    std::vector<Team> teams;
    std::map<Coordinate, AbstractCell*> field;

    void make_teams(size_t teams_count);

    void clear_field();
    void make_water();
    std::vector<CellLand*> make_all_land_cells();
    void set_land_cells(std::vector<CellLand*> &cells);
    void make_field();

public:
    Field() = delete;
    Field(size_t teams_count);
    Field(const Field &other);

    void move(size_t team_num, AbstractResolver &resolver);

    bool is_finished();
    std::tuple<GAME_STATE, std::vector<size_t>> get_result();
};

}