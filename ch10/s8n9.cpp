#include <iostream>
#include <typeinfo>

/*
auto keyword not recommended for functions w/o a good reason
also does not work for function params until c++20 and then it's not type deduction

auto sum(int x, double y)
{
    return x + y;
}
*/


int main()
{
    auto x{ 3 };
    auto y{ 5.1f };
    auto z{ 66.0 };

    auto foo{ x / y };
    auto bar{ y * z };
    
    std::cout << foo << '\t' << typeid(foo).name() << '\n';
    std::cout << bar << '\t' << typeid(bar).name() << '\n';

    return 0;
}