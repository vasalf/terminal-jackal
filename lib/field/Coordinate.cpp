#include "Coordinate.h"

using namespace NJackal;

Coordinate::Coordinate()
: x(0), y(0)
{}

Coordinate::Coordinate(int x, int y)
: x(x), y(y)
{}

Coordinate::Coordinate(const Coordinate &other)
: x(other.get_x()), y(other.get_y())
{}

Coordinate& Coordinate::operator=(const Coordinate &other)
{
    x = other.get_x();
    y = other.get_y();
    return *this;
}

bool Coordinate::operator==(const Coordinate &other) const
{
    return x == other.x && y == other.y;
}

bool Coordinate::operator!=(const Coordinate &other) const
{
    return !(*this == other);
}

bool Coordinate::operator<(const Coordinate &other) const
{
    if (x == other.x)
        return y < other.y;
    return x < other.x;
}

Coordinate& Coordinate::operator+=(const Coordinate &other)
{
    x += other.get_x();
    y += other.get_y();
    return *this;
}

Coordinate& Coordinate::operator-=(const Coordinate &other)
{
    x -= other.get_x();
    y -= other.get_y();
    return *this;
}

Coordinate Coordinate::operator+(const Coordinate &other) const
{
    Coordinate c(*this);
    c += other;
    return c;
}

Coordinate Coordinate::operator-(const Coordinate &other) const
{
    Coordinate c(*this);
    c -= other;
    return c;
}

int Coordinate::get_x() const
{
    return x;
}

int Coordinate::get_y() const
{
    return y;
}

int& Coordinate::x()
{
    return x;
}

int& Coordinate::y()
{
    return y;
}

Coordinate& Coordinate::turn_right()
{
    *this = Coordinate(y, -x);
    return *this;
}