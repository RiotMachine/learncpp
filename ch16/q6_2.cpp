#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& v)
{
    for (std::size_t i{ 0 }; i < v.size(); ++i)
        std::cout << v[i] << '\t';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);
    std::cout << '\n';

    return 0;
}
