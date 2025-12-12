// default arguments(!)

#include "./s5.h"
#include <iostream>

// like py, default arguments must be rightmost

// if both function declaration and definition,
// best practice to set default value in function declaration, not in definition
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