#include "Field.h"

using namespace NJackal;

using std::vector;

void Field::make_teams(size_t teams_count)
{
    teams.clear();
    for (size_t num = 0; num < teams_count; num++)
        teams.push_back(Team(TEAM_START_COORDINATES[num]));
}

void Field::clear_field()
{
    for (auto &row : field)
        for (AbstractCell *&cell : row) {
            delete cell;
            cell = NULL;
        }
}

void Field::make_water()
{
    for (size_t x = 2; x < FIELD_WIDTH - 2; x++) {
        Coordinate c(x, 0);
        field[c] = (AbstractCell*)(new CellWater(c));

        c.set_y(FIELD_HEIGHT - 1);
        field[c] = (AbstractCell*)(new CellWater(c));
    }

    for (size_t y = 2; y < FIELD_HEIGHT - 2; y++) {
        Coordinate c(0, y);
        field[c] = (AbstractCell*)(new CellWater(c));

        c.set_x(FIELD_WIDTH - 1);
        field[c] = (AbstractCell*)(new CellWater(c));
    }

    for (const Coordinate &c : WATER_CORNER_COORDINATES)
        field[c] = (AbstractCell*)(new CellWater(c));
}

void Field::make_all_land_cells()
{
    vector<CellLand*> cells;

    for (size_t i = 0; i < CELL_LAND_COUNT; i++) cells.push_back(new CellLand());

    for (size_t i = 0; i < CELL_ARROW_ONE_DIR_STRAIGHT_COUNT; i++) cells.push_back(new CellArraowOneDirStraight());
    for (size_t i = 0; i < CELL_ARROW_ONE_DIR_DIAGONAL_COUNT; i++) cells.push_back(new CellArraowOneDirDiagonal());
    for (size_t i = 0; i < CELL_ARROW_TWO_DIR_STRAIGHT_COUNT; i++) cells.push_back(new CellArraowTwoDirStraight());
    for (size_t i = 0; i < CELL_ARROW_TWO_DIR_DIAGONAL_COUNT; i++) cells.push_back(new CellArraowTwoDirDiagonal());
    for (size_t i = 0; i < CELL_ARROW_THREE_DIR_COUNT; i++) cells.push_back(new CellArraowThreeDir());
    for (size_t i = 0; i < CELL_ARROW_FOUR_DIR_STRAIGHT_COUNT; i++) cells.push_back(new CellArraowFourDirStraight());
    for (size_t i = 0; i < CELL_ARROW_FOUR_DIR_DIAGONAL_COUNT; i++) cells.push_back(new CellArraowFourDirDiagonal());

    for (size_t i = 0; i < CELL_HORSE_COUNT; i++) cells.push_back(new CellHorse());

    for (size_t i = 0; i < CELL_RUM_COUNT; i++) cells.push_back(new CellRum());

    for (size_t i = 0; i < CELL_WHIRLIGIG_2_COUNT; i++) cells.push_back(new CellWhirligig(2));
    for (size_t i = 0; i < CELL_WHIRLIGIG_3_COUNT; i++) cells.push_back(new CellWhirligig(3));
    for (size_t i = 0; i < CELL_WHIRLIGIG_4_COUNT; i++) cells.push_back(new CellWhirligig(4));
    for (size_t i = 0; i < CELL_WHIRLIGIG_5_COUNT; i++) cells.push_back(new CellWhirligig(5));

    for (size_t i = 0; i < CELL_ICE_COUNT; i++) cells.push_back(new CellIce());

    for (size_t i = 0; i < CELL_TRAP_COUNT; i++) cells.push_back(new CellTrap());

    for (size_t i = 0; i < CELL_CROCODILE_COUNT; i++) cells.push_back(new CellCrocodile());

    for (size_t i = 0; i < CELL_CANNIBAL_COUNT; i++) cells.push_back(new CellCannibal());

    for (size_t i = 0; i < CELL_FORTRESS_COUNT; i++) cells.push_back(new CellFortress());
    for (size_t i = 0; i < CELL_FORTRESS_ABORIGINE_COUNT; i++) cells.push_back(new CellFortressAborigine());

    for (size_t i = 0; i < CELL_GOLD_1_COUNT; i++) cells.push_back(new CellGold(1));
    for (size_t i = 0; i < CELL_GOLD_2_COUNT; i++) cells.push_back(new CellGold(2));
    for (size_t i = 0; i < CELL_GOLD_3_COUNT; i++) cells.push_back(new CellGold(3));
    for (size_t i = 0; i < CELL_GOLD_4_COUNT; i++) cells.push_back(new CellGold(4));
    for (size_t i = 0; i < CELL_GOLD_5_COUNT; i++) cells.push_back(new CellGold(5));

    for (size_t i = 0; i < CELL_BALLOON_COUNT; i++) cells.push_back(new CellBalloon());

    for (size_t i = 0; i < CELL_PLANE_COUNT; i++) cells.push_back(new CellPlane());

    for (size_t i = 0; i < CELL_GUN_COUNT; i++) cells.push_back(new CellGun());

    Utils::shuffle(cells);

    return cells;
}

void Field::set_land_cells(const vector<CellLand*> &cells)
{
    size_t cell_num = 0;

    for (size_t x = 1; x < FIELD_WIDTH - 1; x++)
        for (size_t y = 2; y < FIELD_HEIGHT - 2; y++) {
            Coordinate c(x, y);
            field[c] = (AbstractCell*)(cells[cell_num++]);
            field[c].set_coord(c);
        }

    for (size_t x = 2; x < FIELD_WIDTH - 2; x++) {
        Coordinate c(x, 1);
        field[c] = (AbstractCell*)(cells[cell_num++]);
        field[c].set_coord(c);

        c.set_y(FIELD_HEIGHT - 2);
        field[c] = (AbstractCell*)(cells[cell_num++]);
        field[c].set_coord(c);
    }
}

void Field::make_field()
{
    clear_field();

    make_water();

    vector<CellLand*> land_cells = make_all_land_cells();
    set_land_cells(land_cells);
}

Field::Field(size_t teams_count)
{
    make_teams(teams_count);
    make_field();
}

void Field::move(size_t team_num, AbstractResolver &resolver)
{
    Team &team = teams[team_num];

    vector<int> chip_nums(1, -1); // ship can move always

    for (size_t pirate_num : team.get_pirates_nums())
        if //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    resolver.choose_chip_to_move(*this, team_num, )
}