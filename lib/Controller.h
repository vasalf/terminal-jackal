#pragma once

#include "UI.h"
#include "Map.h"

#include <vector>
#include <memory>

namespace NJackal {

class Controller {
private:
    Controller(Controller &) = delete;
    Controller(Controller &&) = delete;
    Controller & operator=(Controller &) = delete;
    Controller & operator=(Controller &&) = delete;

public:
    Controller() = default;

    void run() const;
};

}
