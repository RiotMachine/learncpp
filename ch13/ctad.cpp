#include "ctad.h"
#include <iostream>
#include <utility>

// function templates and class templates are usually defined in header files

// CTAD cant deduce template arguments for aggregate class templates in C++17
// needs a little helper (aww)
template <typename T, typename U>
Triplet(std::pair<T, T>, U) -> Triplet<T, U>;

int main()
{
    // Class Template Argument Deduction
    std::pair<int, double> p1{ 7, 8.9 };
    std::pair p2{ 9.0, 0.9 };

    Triplet t1{ std::pair{ 7, 8 }, 8.1 };
    Triplet t2;

    printCoordinate(p1);

    // printCoordinate(T p) in p2's case resolves to printCoordinate<std::pair<double, double>>
    // void printCoordinate(std::pair p) wouldnt work since CTAD isnt parameter deduction
    // would need (std::pair<double, double> p)  or (std::pair<T, T> p)
    printCoordinate(p2);
    printCoordinate(t1.pair);
    printCoordinate(t2.pair);

    return 0;
}
