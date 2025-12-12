// function overloading && deletes

#include <iostream>

void foo(int x)
{
    std::cout << "foo(int)\n";
}

void foo(double x)
{
    std::cout << "foo(double)\n";
}

void foo(float) = delete;

int main()
{
    // double matches with double
    std::cout << "foo(double)?\t";
    foo(3.14);
    // will not compile since we 'deleted' calling foo() with a float
    std::cout << "foo(double)?\t";
    foo(3.0f);
    
    return 0;
}