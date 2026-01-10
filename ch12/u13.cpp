// in and out parameters
/// in parameter is one being used w/in function
/// out parameter is one whose value is being modifed (ie a ref or ptr)
//// instead of returning that val then assigning it

#include <cmath>
#include <iostream>

// in getTrig, degrees is an in parameter while the trigs are out parameters
void getTrig(double degrees, double& sinOut, double& cosOut, double& tanOut)
{
    constexpr double pi{ 3.14159265358979323846 };
    double radians{ degrees * pi / 180.0 };
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
    tanOut = std::tan(radians);

    if (fmod(degrees, 180.0) == 0)
    {
        sinOut = 0.0;
        tanOut = 0.0;
    }
    if ((fmod(degrees, 90.0) == 0) && (fmod(degrees, 180.0) != 0))
    {
        cosOut = 0.0;
    }
}

int main()
{
    std::cout << "Enter the degrees of your angle: ";
    double angle{};
    std::cin >> angle;

    double sin{ };
    double cos{ };
    double tan{ };
    getTrig(angle, sin, cos, tan);

    std::cout << "For an angle of " << angle << " degrees\n";
    std::cout << "\tsin = " << sin << '\n';
    std::cout << "\tcos = " << cos << '\n';
    std::cout << "\ttan ";
    if (cos == 0.0)
        std::cout << "is undefined\n";
    else
        std::cout << "= " << tan << '\n';

    return 0;
}
