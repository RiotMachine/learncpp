#include <iostream>

namespace mathConsts
{
    constexpr double pi = 3.14159;
}

constexpr double calcCircum(double radius)
{
    return 2 * mathConsts::pi * radius;
}

int main()
{
    // calcCircum() evaluates @ compile time since 3 is constexpr
    // since calcCircum() is a constexpr function,
    /// its return value can be known at compile time and used to initialize a
    /// constexpr variable
    constexpr double circumference{calcCircum(3)};

    std::cout << circumference << '\n';

    // calcCircum() evaluates @ runtime since x is not constexpr
    int x{4};
    std::cout << "The circumference of a circle with r = 4 is "
        << calcCircum(x) << '\n';

    return 0;
}
