#include "Controller.h"

using namespace NJackal;

using std::vector;
using std::tie;

void Controller::run() const {
    UI ui;

    size_t human_players_count;
    size_t bot_players_count;
    tie(human_players_count, bot_players_count) = ui.choose_players_config();

    BotRandom bot;

    vector<AbstractResolver&> resolvers;
    for (int i = 0; i < human_players_count; i++) resolvers.push_back(ui);
    for (int i = 0; i < bot_players_count; i++) resolvers.push_back(bot); 
    Utils::shuffle(resolvers);

    Field field(resolvers.size());
    
    while (!field.is_finished()) {
        for (size_t num = 0; num < resolvers.size(); num++) {
            ui.start_move(field, num);
            field.move(num, resolvers[num]);
        }
    }

    ui.show_result(field, field.get_result());
}
