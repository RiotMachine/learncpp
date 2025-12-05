// narrowing conversions

#include <iostream>
#include <iomanip>

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
    // explicitly narrow when possible
    // is a narrowing conversion even though 5.0 is a constexpr
    constexpr double d{ 5.0 };
    printFcn(static_cast<int>(d));

    // not considered to be narrowing since
    // constexpr & (unsigned) int can hold 5
    constexpr int n1{ 5 };
    constexpr unsigned int u1{ n1 };
    printFcn(u1);

    // not narrowing (even though loss of precision results) 
    // since number is constant and in the range of float
    float f { 0.10000000000000 };
    printFloat(f);

    return 0;
}