#ifndef ALIAS_H
#define ALIAS_H

#include <iostream>

// alias template
template <typename T>
using Coord = std::pair<T, T>;

template <typename T=int, typename U=double>
struct Triplet
{
    std::pair<T, T> pair{ 0, 0 };
    U third{ };
};

template <typename T>
void printCoordinate(T p)
{
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

#endif
