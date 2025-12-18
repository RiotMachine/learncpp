#ifndef S10_H
#define S10_H

#include <iostream>

template <int N>
constexpr int factorial()
{
    static_assert(N >= 0, "factorial<N>: N must be non-negative");

    int product{1};
    for (int i{N}; i > 1; --i)
    {
        product *= i;
    }
    return product;
}

template <int N>
void printCalcs()
{
    std::cout << N << "! is " << factorial<N>() <<'\n';
}

#endif