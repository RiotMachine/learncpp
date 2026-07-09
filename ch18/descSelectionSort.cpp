#include <array>
#include <iostream>

using Idx = std::size_t;

int main()
{
    std::array arr{ 30, 50, 20, 10, 40 };

    for (Idx startIdx{ 0 }; startIdx < arr.size()-1; ++startIdx)
    {
        Idx maxIdx{ startIdx };
        for (Idx currentIdx{ startIdx+1 }; currentIdx < arr.size(); ++ currentIdx)
        {
            if (arr[currentIdx] > arr[maxIdx])
                maxIdx = currentIdx;
        }
        std::swap(arr[startIdx], arr[maxIdx]);
    }

    for (const auto e : arr)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}