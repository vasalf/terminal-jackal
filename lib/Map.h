#pragma once

#include "UI.h"
#include "AbstractPlayer.h"

#include <vector>
#include <memory>

namespace NJackal {

class Map {
private:
    std::vector<std::shared_ptr<AbstractPlayer>> players;

public:
    Map() = default;

    void set_players(const std::vector<std::shared_ptr<AbstractPlayer>> &players);
};

}
