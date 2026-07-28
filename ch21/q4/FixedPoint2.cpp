#include "FixedPoint2.h"
#include <cstdint>
#include <ostream>

FixedPoint2::operator double() const
{
    std::int32_t bigDigits{ m_base * 100 + m_decimal };
    return bigDigits / 100.0;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
    return out << static_cast<double>(fp);
}

bool testDecimal(const FixedPoint2& fp)
{
    if (fp.m_base >= 0)
        return fp.m_decimal >= 0 && fp.m_decimal < 100;
    else
        return fp.m_decimal <= 0 && fp.m_decimal > -100;
}