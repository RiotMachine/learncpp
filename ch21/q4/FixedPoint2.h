#ifndef FIXEDPOINT2_H
#define FIXEDPOINT2_H

#include <cassert>
#include <cmath>
#include <cstdint>
#include <iosfwd>


class FixedPoint2
{
public:
    using Base = std::int16_t;
    constexpr static Base BASE_MAX{ INT16_MAX };
    constexpr static Base BASE_MIN{ INT16_MIN };
    using Decimal = std::int8_t;
    constexpr static Decimal DECIMAL_MAX{ INT8_MAX };
    constexpr static Decimal DECIMAL_MIN{ INT8_MIN };


    FixedPoint2(Base x, Decimal y)
        : m_base{ x }, m_decimal{ y }
    {
        if (m_base < 0 || m_decimal < 0)
        {
            if (m_base > 0)
                m_base = -m_base;
            else if (m_decimal > 0)
                m_decimal = -m_decimal;
        }
        boundDecimal();
    }

    FixedPoint2(double d)
    {
        double base{ };
        double decimal{ std::modf(d, &base) };
        decimal = std::round(decimal * 100);

        assert(base >= BASE_MIN && base <= BASE_MAX);
        m_base = static_cast<Base>(base);
        m_decimal = static_cast<Decimal>(decimal);
        boundDecimal();
    }

    explicit operator double() const;
    FixedPoint2 operator-() const;

    friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2);
    friend FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2);
    friend bool testDecimal(const FixedPoint2& fp);

private:
    // ensure m_decimal is [-99, 99]
    void boundDecimal()
    {
        m_base += m_decimal / 100;
        m_decimal %= 100;
    }

    Base m_base{ };
    Decimal m_decimal{ };
};

std::istream& operator>>(std::istream& in, FixedPoint2& fp);
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp);

#endif