// use type aliases for degrees and radians values
#include <iostream>

namespace constants
{
    constexpr double pi { 3.14159 };
}

using Degrees = double;
using Radians = double;

/*
'radians = degrees' would be allowed since we're assinging a var with type double 
to double, but not best practice since we want different user-defined types to be 
semantically distinct even if they share an underlying data type
*/

Radians convertToRadians(Degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}