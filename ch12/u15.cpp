// std::optional

#include <iostream>
#include <cmath>
#include <optional>

using Degrees = double;

std::optional<double> getTan(Degrees d)
{
    if (fmod(d, 180.0) == 0)
        return 0;
    else if (fmod(d, 90) == 0)
        return { };
    else
    {
        constexpr double pi{ 3.14159265358979323846 };
        const double radians{ d * pi / 180.0 };
        return std::tan(radians);
    }
}

int main()
{
    std::cout << "Enter the degrees of your angle: ";
    double angle{};
    std::cin >> angle;

    std::optional<double> tan{ getTan(angle) };

    std::cout << "For an angle of " << angle << " degrees tan ";
    if (tan)
        std::cout << "= " << *tan << '\n';
    else
        std::cout << "is undefined.\n";

    return 0;
}
