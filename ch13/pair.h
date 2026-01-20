#ifndef PAIR_H
#define PAIR_H

#include <iostream>

// template defs and type definitions are exempt from ODR

template <typename T, typename U>
struct Triplet
{
    int first{ };
    T second{ };
    T third{ };
};

// since printCoordinate uses generic type, can accept any type that has members 'first' and 'second'
template <typename T>
void printCoordinate(T p)
{
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

#endif
