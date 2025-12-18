#ifndef S10_H
#define S10_H

#include <iostream>

// with non-type template parameters, numeric conversions are more limited (int to double wont work)
// also, they perform more limited matching than type template parameters. 
/// if I were to define template <char N> as well we would get ambiguous matches

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