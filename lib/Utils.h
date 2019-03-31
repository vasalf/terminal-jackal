#pragma once

#include <vector>

namespace NJackal {

class Utils {
public:
    Controller() = delete;

    template <class T>
    static void shuffle(std::vector<T> &v) {
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(v.begin(), v.end(), g);
    }
};

}
