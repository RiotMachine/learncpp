#include <cstdint>
#include <iostream>
#include <typeinfo>

using PrintError = int;
PrintError printData();

int main()
{
    // int8_t is really just a typedef for a signed char
    using MyTypedef = signed char;
    std::int8_t x{ 97 };
    MyTypedef y{ 97 };
    std::cout << x << typeid(x).name() << '\t' << y << typeid(y).name() << '\n';
}