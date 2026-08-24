#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>
#include <vector>

int getLargestRadius(const std::vector<Shape*>& arr)
{
    int maxRadius{ };
    for (const auto* shapePtr : arr)
    {
        auto circlePtr{ dynamic_cast<const Circle*>(shapePtr) };
        if (circlePtr)
            maxRadius = std::max(maxRadius, circlePtr->radius());
    }
    return maxRadius;
}

int main()
{
    std::vector<Shape*> v{
        new Circle   { {1,2}, 7 },
        new Triangle { {1,2}, {3,4}, {5,6} },
        new Circle   { {7,8}, 3 }
    };

    for (const auto* shapePtr : v)
        std::cout << *shapePtr << '\n';

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    for (const auto* shapePtr : v)
        delete shapePtr;

    return 0;
}
