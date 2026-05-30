#include <iostream>
#include <limits>
#include <optional>
#include <vector>

int getInt()
{
    int x{ 0 };
    do
    {
        std::cout << "Enter an int between 1 and 9: ";
        std::cin >> x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (x < 1 || x > 9);
    return x;
}

template <typename T>
void printArray(const std::vector<T>& v)
{
    for (std::size_t i{ 0 }; i < v.size(); ++i)
        std::cout << v[i] << '\t';
}

template <typename T>
std::optional<std::size_t> searchArray(const std::vector<T>& v, T x)
{
    for (std::size_t i{ 0 }; i < v.size(); ++i)
        if (v[i] == x)
            return i;
    return { };
}

int main()
{
    int x{ getInt() };
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);
    std::cout << '\n';

    std::optional<std::size_t> idx{ searchArray(arr, x) };

    std::cout << "The number " << x;
    if (idx)
        std::cout << " has index " << *idx;
    else
        std::cout << " was not found";

    std::cout << '\n';

    return 0;
}
