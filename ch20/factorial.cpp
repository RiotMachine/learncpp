#include <cassert>
#include <iostream>
#include <vector>

using Idx = std::size_t;

// assumes incremental access of factorial()
int factorial(Idx n)
{
    assert (n >= 0);
    static std::vector factorials{ 1 };
    if (n >= factorials.size())
        factorials.push_back(n * factorial(n-1));
    return factorials[n];
}

int main()
{
    constexpr int LIMIT{ 7 };
    for (Idx i{ }; i < LIMIT; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';

    return 0;
}