#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

struct Point2D
{
    int x{ };
    int y{ };
};

inline std::ostream& operator<<(std::ostream& out, const Point2D& c)
{
    return out << "Point(" << c.x << ", " << c.y << ')';
}

#endif
