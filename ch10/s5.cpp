// arithetic conversions

#include <iostream>
#include <iomanip>
#include <typeinfo>

void printFcn(int i)
{
    std::cout << i << '\n';
}

void printFloat(float f)
{
    std::cout << std::setprecision(10) << f << '\n';
}

int main()
{
    constexpr double d{ 5.0 };
    constexpr int n1{ 5 };
    constexpr unsigned int u1{ n1 };
    short s { 3 };
    float f { 0.1000 };

    // float + int becomes float
    std::cout << n1 + f << typeid(n1 + f).name() << '\n';
    // short + short gets promoted to int
    std::cout << s + s << typeid(s + s).name() << '\n';
    // int cant represent all vals of unsigned int so 
    // both operands are converted to unsigned type of signed operand
    // in these cases unsigned int
    std::cout << 5u-10 << typeid(5u-10).name() << '\n';
    std::cout << std::boolalpha << (-3 < 5u) << '\n';

    return 0;
}