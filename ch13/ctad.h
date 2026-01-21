#ifndef CTAD_H
#define CTAD_H

#include <iostream>

// template defs and type definitions are exempt from ODR

// template parameters can have default values
template <typename T=int, typename U=double>
struct Triplet
{
    // CTAD doesnt work with non-static member initialization
    std::pair<T, T> pair{ 0, 0 };
    U third{ };
};

// since printCoordinate uses generic type, can accept any type that has members 'first' and 'second'
template <typename T>
void printCoordinate(T p)
{
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

#endif
