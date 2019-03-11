#include "Controller.h"

using namespace NJackal;

using std::vector;
using std::shared_ptr;
using std::make_shared;

void Controller::run() const {
    Map map();
    UI ui(map);

    size_t human_players_count = ui.choose_human_players_count();
    size_t bots_players_count = ui.choose_bots_players_count();

    vector<shared_ptr<AbstructPlayer>> players;
    for (int i = 0; i < human_players_count; i++) players.push_back(make_shared<HumanPlayer>(i, ui));
    for (int i = 0; i < bots_players_count; i++) players.push_back(make_shared<BotPlayer>(human_players_count + i, map));

    map.set_players(players);
    
    while (true) {
        for (shared_ptr<AbstructPlayer> player : players) {
            map.draw_map();

            ui.start_move(player->get_numper());

            player->move();
        }
    }
}
