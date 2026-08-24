#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
void printArr(const std::vector<T*>& arr)
{
    for (const auto* ptr : arr)
    {
        if (ptr)
            std::cout << *ptr << '\n';
    }
}

template <typename T>
void printArr(const std::vector<std::unique_ptr<T>>& arr)
{
    for (const auto& ptr : arr)
    {
        if (ptr)
            std::cout << *ptr << '\n';
    }
}

int getLargestRadius(const std::vector<Shape*>& arr)
{
    int maxRadius{ };
    for (const auto* shapePtr : arr)
    {
        if (auto circlePtr{ dynamic_cast<const Circle*>(shapePtr) })
            maxRadius = std::max(maxRadius, circlePtr->radius());
    }
    return maxRadius;
}

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& arr)
{
    int maxRadius{ };
    for (const auto& shapePtr : arr)
    {
        if (auto circlePtr{ dynamic_cast<const Circle*>(shapePtr.get()) })
            maxRadius = std::max(maxRadius, circlePtr->radius());
    }
    return maxRadius;
}

int main()
{
    std::vector<Shape*> arrRaw{
        new Circle   { {1,2}, 7 },
        new Triangle { {1,2}, {3,4}, {5,6} },
        new Circle   { {7,8}, 3 }
    };

    std::vector<std::unique_ptr<Shape>> arrUnique;
    arrUnique.reserve(3);

    arrUnique.push_back(
        std::make_unique<Circle>(Point2D {1,2}, 7)
    );
    arrUnique.push_back(
        std::make_unique<Triangle>(Point2D {1,2}, Point2D {3,4}, Point2D {5,6})
    );
    arrUnique.push_back(
        std::make_unique<Circle>(Point2D {7,8}, 3)
    );

    printArr(arrUnique);

    std::cout << "The largest radius is: " << getLargestRadius(arrUnique) << '\n';

    for (const auto* shapePtr : arrRaw)
        delete shapePtr;

    return 0;
}
