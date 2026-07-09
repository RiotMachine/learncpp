#include <array>
#include <iostream>

using Idx = std::size_t;

int main()
{
    std::array arr{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    bool sorted{ false };

    for (Idx boundary{ arr.size() }; boundary != 0; --boundary)
    {
        sorted = true;
        for (Idx i{ }; i < boundary-1; ++i)
        {
            if (arr[i] > arr[i+1])
            {
                sorted = false;
                std::swap(arr[i], arr[i+1]);
            }
        }
        if (sorted)
        {
            std::cout << "Early termination on iteration " 
                << arr.size()-boundary+1 << '\n';
            break;
        }
    }

    for (const auto e : arr)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}