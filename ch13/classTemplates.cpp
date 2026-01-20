#include <iostream>

template <typename T, typename U>
struct Coordinate
{
    T x{ };
    U y{ };
};

template <typename T, typename U>
constexpr void printCoordinate(Coordinate<T,U> p)
{
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}

int main()
{
    // templates with mult template types can have both types be same or diff
    Coordinate<int, double> c1{ 3, 4.2 };
    Coordinate<int, int> c2{ 4, 7 };

    printCoordinate(c1);
    printCoordinate(c2);

    return 0;
}
