#include <array>
#include <iostream>

using Idx = std::size_t;

int main()
{
    std::array arr{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    for (Idx boundary{ arr.size() }; boundary != 0; --boundary)
    {
        for (Idx i{ }; i < boundary-1; ++i)
        {
            if (arr[i] > arr[i+1])
                std::swap(arr[i], arr[i+1]);
        }
    }

    for (const auto e : arr)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}