#include "FixedPoint2.h"
#include <cassert>
#include <cstdint>
#include <iostream>


FixedPoint2::operator double() const
{
    std::int32_t bigDigits{ m_base * 100 + m_decimal };
    return bigDigits / 100.0;
}

FixedPoint2 FixedPoint2::operator-() const
{
    assert(-m_base >= BASE_MIN && -m_base <= BASE_MAX);
    assert(-m_decimal >= DECIMAL_MIN && -m_decimal <= DECIMAL_MAX);

    return FixedPoint2 { 
        static_cast<Base>(-m_base), static_cast<Decimal>(-m_decimal) 
    };
}


// friend functions
bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    return (fp1.m_base == fp2.m_base) && (fp1.m_decimal == fp2.m_decimal);
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    assert (
        fp1.m_base + fp2.m_base >= FixedPoint2::BASE_MIN
        &&  fp1.m_base + fp2.m_base <= FixedPoint2::BASE_MAX
    );

    std::int64_t bigDigit{
        fp1.m_base*100 + fp2.m_base*100 + fp1.m_decimal + fp2.m_decimal 
    };
    return FixedPoint2 {
        static_cast<FixedPoint2::Base>(bigDigit / 100),
        static_cast<FixedPoint2::Decimal>(bigDigit % 100) 
    };
}

bool testDecimal(const FixedPoint2& fp)
{
    if (fp.m_base >= 0)
        return fp.m_decimal >= 0 && fp.m_decimal < 100;
    else
        return fp.m_decimal <= 0 && fp.m_decimal > -100;
}


// non-friend functions
std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
    double d{};
    in >> d;
    fp = FixedPoint2 { in ? d : 0 };
    return in;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
    return out << static_cast<double>(fp);
}