#pragma once

namespace NJackal {

class Coordinate {
private:
    int x, y;

public:
    Coordinate();
    Coordinate(int x, int y);
    Coordinate(const Coordinate &other);

    Coordinate& operator=(const Coordinate &other);

    bool operator==(const Coordinate &other) const;
    bool operator!=(const Coordinate &other) const;
    bool operator<(const Coordinate &other) const;

    Coordinate& operator+=(const Coordinate &other);
    Coordinate& operator-=(const Coordinate &other);

    Coordinate operator+(const Coordinate &other) const;
    Coordinate operator-(const Coordinate &other) const;

    int get_x() const;
    int get_y() const;

    int& x();
    int& y();

    Coordinate& turn_right();
};

}
