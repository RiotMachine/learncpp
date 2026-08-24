#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point2D.h"
#include "Shape.h"
#include <iostream>

class Triangle : public Shape
{
public:
    Triangle(Point2D p1, Point2D p2, Point2D p3)
      : m_vertexOne{ p1 }, m_vertexTwo{ p2 }, m_vertexThree{ p3 } {}

private:
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_vertexOne << ", " << m_vertexTwo
                   << ", " << m_vertexThree << ')';
    }

    Point2D m_vertexOne{ };
    Point2D m_vertexTwo{ };
    Point2D m_vertexThree{ };
};

#endif
