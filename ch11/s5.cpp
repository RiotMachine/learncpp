// default arguments(!)

#include "./s5.h"
#include <iostream>

// like py, default arguments must be rightmost
void foo(int x, int y)
{
    std::cout << "x is " << x << " and y is " << y << '\n';
}

int main()
{
    int x{10};

    foo(x);
    foo(x, 20);
}