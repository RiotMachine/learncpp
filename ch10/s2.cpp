// demo of floating-point and integral promotion

#include <iomanip>
#include <iostream>

void printDouble(double d, int precision)
{
    std::cout << std::showpoint << std::setprecision(precision);
    std::cout << d << '\n';
}

void printInt(int i)
{
    std::cout << i <<'\n';
}

int main()
{
    printDouble(5.0, 2);    // double
    printDouble(4.0f, 2);   // float

    printInt(2);    // int
    short s{ 3 };
    printInt(s);    // short
    printInt('a');  // char
    printInt(true); // bool

    return 0;
}