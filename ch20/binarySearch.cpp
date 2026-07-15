#include <array>
#include <iostream>

using Idx = std::size_t;


template <typename T, Idx N>
Idx iterative(const std::array<T, N>& arr, T target)
{
    const Idx sentinel{ arr.size() };

    if (arr.empty())
        return sentinel;
    
    Idx min{ 0 };
    Idx max{ arr.size()-1 };

    while (min <= max)
    {
        const Idx midpoint{ min + ((max-min) / 2) };
        if (arr[midpoint] < target)
            min = midpoint + 1;
        else if (arr[midpoint] > target)
        {
            if (midpoint == 0)
                break;
            max = midpoint - 1;
        }
        else
            return midpoint;
    }

    return sentinel;
}

template <typename T, Idx N>
Idx recursive(const std::array<T, N>& arr, T target, Idx max, Idx min=0)
{
    const Idx sentinel{ arr.size() };

    if (arr.empty())
        return sentinel;

    if (min > max)
        return sentinel;
    const Idx midpoint{ min + ((max-min) / 2) };
    if (arr[midpoint] < target)
        return recursive(arr, target, max, midpoint+1);
    else if (arr[midpoint] > target)
    {
        if (midpoint == 0)
            return sentinel;
        return recursive(arr, target, midpoint-1, min);
    }
    else
        return midpoint;
}

int main()
{
    constexpr std::array arr{
        3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48
    };

    constexpr std::array searchVals{
        0, 3, 12, 13, 22, 26, 43, 44, 48, 49
    };

    constexpr Idx sentinel{ arr.size() };

    constexpr std::array<Idx, searchVals.size()> expectedResults{
        sentinel, 0, 3, sentinel, sentinel, 8, sentinel, 13, 14, sentinel
    };

    for (Idx i; i < searchVals.size(); ++i)
    {
        int val{ searchVals[i] };
        Idx result{ recursive(arr, val, arr.size()) };
        std::cout << "test value " << val
            << (result == expectedResults[i] ? " passed." : " failed.")
            << '\n';
    }

    return 0;
}