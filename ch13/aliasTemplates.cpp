#include "alias.h"
#include <iostream>
#include <utility>

// function templates and class templates are usually defined in header files

// CTAD needs helper to deduce template arguments for aggregate class templates in C++17
template <typename T, typename U>
Triplet(Coord<T>, U) -> Triplet<T, U>;

int main()
{
    using CartesianPoint = std::pair<double, double>;
    CartesianPoint cp1{ 9.0, 0.9 };

    Coord<int> c1{ 4, 3 };
    Triplet t1{ Coord<double>{ 7, 8 }, 8.1 };

    printCoordinate(cp1);
    printCoordinate(c1);
    printCoordinate(t1.pair);

    return 0;
}
