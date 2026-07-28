#include "FixedPoint2.h"
#include <cassert>
#include <iostream>


int main()
{
    FixedPoint2 a{ 1, 104 };
    std::cout << a << '\n';
    std::cout << static_cast<double>(a) << '\n';
    assert(static_cast<double>(a) == 2.04);
    assert(testDecimal(a));

    FixedPoint2 b{ 1, -104 };
    assert(static_cast<double>(b) == -2.04);
    assert(testDecimal(b));

    FixedPoint2 c{ -1, 104 };
    assert(static_cast<double>(c) == -2.04);
    assert(testDecimal(c));

    FixedPoint2 d{ -1, -104 };
    assert(static_cast<double>(d) == -2.04);
    assert(testDecimal(d));

    return 0;
}
