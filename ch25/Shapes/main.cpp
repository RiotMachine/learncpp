#include "Circle.h"
#include "Triangle.h"
#include <iostream>

int main()
{
    Circle c{ {1,2}, 7 };
    std::cout << c << '\n';

    Triangle t{ {1,2}, {3,4}, {5,6} };
    std::cout << t << '\n';

    return 0;
}
