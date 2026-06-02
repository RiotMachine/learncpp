#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& v)
{
    if (v.empty())
        return T{ };
    std::size_t maxIDX{ 0 };
    for (std::size_t i{ 1 }; i < v.size(); ++i)
        if (v[i] > v[maxIDX])
            maxIDX = i;
    return v[maxIDX];
}


int main()
{
    std::vector data1{ 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2{ -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3{ };
    std::cout << findMax(data3) << '\n';

    return 0;
}
