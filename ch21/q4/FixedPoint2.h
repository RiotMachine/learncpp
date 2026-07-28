#ifndef FIXEDPOINT2_H
#define FIXEDPOINT2_H

#include <cassert>
#include <cstdint>
#include <ostream>

class FixedPoint2
{
public:
    FixedPoint2(int x, int y)
    {
        assert(x >= INT16_MIN && x <= INT16_MAX);
        assert(y >= INT8_MIN && y <= INT8_MAX);

        if (x < 0 || y < 0)
        {
            if (x > 0)
                x = -x;
            else if (y > 0)
                y = -y;
        }
        x += y / 100;
        y %= 100;

        m_wholeDigits = x;
        m_fractDigits = y;
    }

    explicit operator double() const;

    friend bool testDecimal(const FixedPoint2 &fp);

private:
    std::int16_t m_wholeDigits{ };
    std::int8_t m_fractDigits{ };
};

#endif