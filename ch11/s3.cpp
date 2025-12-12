// function overloading

#include <iostream>

void foo(int x)
{
    std::cout << "foo(int)\n";
}

void foo(double x)
{
    std::cout << "foo(double)\n";
} 

void bar(char x, unsigned int y)
{
    std::cout << "bar(char, unsigned int)\n";
}

void bar(char x, const double y)
{
    std::cout << "bar(char, const double)\n";
}

int main()
{
    // double matches with double
    std::cout << "foo(double)?\t";
    foo(3.14);
    // promotion from lesser floating-point type to double matches double
    std::cout << "foo(double)?\t";
    foo(3.0f);
    // have to cast since long can be converted to either int or double
    std::cout << "foo(int)?\t";
    foo(static_cast<int>(5L));
    
    std::cout << '\n';

    // with multiple parameters, all matches have to be equal except one that is better
    // int to either unsigned int or double is conversion,
    // so explicitly marking 2nd parameter as unsigned int
    std::cout << "bar(char, unsigned int)?\t";
    bar(4, 5u);
    // consts are dropped when evaling overload match
    // so if I had a bar with two params whose 
    // second param was a const double or a reference to a double
    // compilation would fail due to ambiguous match
    std::cout << "bar(char, const double)?\t";
    bar('a', 5.2);
    return 0;
}