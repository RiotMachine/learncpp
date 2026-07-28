#include "FixedPoint2.h"
#include <cassert>
#include <iostream>

int main()
{
    FixedPoint2 a{ 0.01 };
    assert(static_cast<double>(a) == 0.01);

    FixedPoint2 b{ -0.01 };
    assert(static_cast<double>(b) == -0.01);

    FixedPoint2 c{ 1.9 };
    assert(static_cast<double>(c) == 1.9);

    FixedPoint2 d{ 5.01 };
    assert(static_cast<double>(d) == 5.01);

    FixedPoint2 e{ -5.01 };
    assert(static_cast<double>(e) == -5.01);

    FixedPoint2 f { 106.9978 }; // should be stored with base 107 and decimal 0
    assert(static_cast<double>(f) == 107.0);

    FixedPoint2 g { -106.9978 }; // should be stored with base -107 and decimal 0
    assert(static_cast<double>(g) == -107.0);

    std::cout << "Made it!\n";

    return 0;
}