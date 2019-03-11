#pragma once

namespace NJackal {

enum class ChipType {SHIP, PIRATE_0 = 0, PIRATE_1 = 1, PIRATE_2 = 2};

class UI {
private:
    PLAYERS_MAX_COUNT = 4;

    UI(UI &) = delete;
    UI(UI &&) = delete;
    UI & operator=(UI &) = delete;
    UI & operator=(UI &&) = delete;

public:
    UI(const Map &map);

    void draw_map();

    void start_move(size_t num);

    size_t choose_human_players_count();
    size_t choose_bots_players_count();

    ChipType choose_chip();
    std::tuple<int, int> choose_move();
    void move_desert();
};

}
