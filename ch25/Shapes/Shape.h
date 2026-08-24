#ifndef SHAPE_H
#define SHAPE_H

#include <iosfwd>

class Shape
{
public:
    virtual ~Shape() = default;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s)
    {
        return s.print(out);
    }

protected:
    virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
