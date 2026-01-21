#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>

template <typename T>
struct Triad
{
    T m1{ };
    T m2{ };
    T m3{ };
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& t)
{
    std::cout << '[' << t.m1 << ", " << t.m2 << ", " << t.m3 << ']';
}

#endif
