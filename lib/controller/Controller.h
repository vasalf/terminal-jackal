#pragma once

#include "Utils.h"
#include "ui/UI.h"
#include "field/Field.h"

#include <vector>

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
