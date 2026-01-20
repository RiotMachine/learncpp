#include "pair.h"
#include <iostream>
#include <utility>

// function templates and class templates are usually defined in header files

int main()
{
    std::pair<int, double> p1{ 7, 8.9 };
    std::pair<double, double> p2{ 9.0, 0.9 };

    // Triplet takes an int as its first param
    Triplet<double, double> t1{ 7, 8.2, 8.1 };

    printCoordinate(p1);
    printCoordinate(p2);
    printCoordinate(t1);

    return 0;
}
