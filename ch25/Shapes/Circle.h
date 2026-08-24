#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point2D.h"
#include "Shape.h"
#include <iostream>

class Circle final : public Shape
{
public:
    Circle(const Point2D& p, int radius)
      : m_center{ p }, m_radius{ radius } {}

    int radius() const { return m_radius; }

private:
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Circle(" << m_center << ", " << "radius "
                   << m_radius << ')';
    }

    Point2D m_center{ };
    int m_radius{ };
};

#endif
