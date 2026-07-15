// Binary search algos returning index of value, or array size if not found
// Search range is [min, max)

#include <array>
#include <iostream>

using Idx = std::size_t;


template <typename T, Idx N>
Idx iterative(const std::array<T, N>& arr, T target)
{
    Idx min{ 0 };
    Idx max{ arr.size() };

    while (min < max)
    {
        const Idx midpoint{ min + ((max-min) / 2) };
        if (arr[midpoint] < target)
            min = midpoint + 1;
        else if (arr[midpoint] > target)
            max = midpoint;
        else
            return midpoint;
    }

    return arr.size();
}


template <typename T, Idx N>
Idx recursive(const std::array<T, N>& arr, T target, Idx min, Idx max)
{
    if (min >= max)
        return arr.size();

    const Idx midpoint{ min + ((max-min) / 2) };
    if (arr[midpoint] < target)
        return recursive(arr, target, midpoint+1, max);
    else if (arr[midpoint] > target)
        return recursive(arr, target, min, midpoint);
    else
        return midpoint;
}


void printTest(Idx result, Idx expected)
{
    std::cout << (result == expected ? " passed" : " failed") << '\n';
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

    for (Idx i{ }; i < searchVals.size(); ++i)
    {
        int val{ searchVals[i] };

        std::cout << "test value " << val << ":\n"
            << "\tIterative: ";
        printTest(iterative(arr, val), expectedResults[i]);
        std::cout << "\tRecursive: ";
        printTest(recursive(arr, val, 0, arr.size()), expectedResults[i]);
        
        std::cout << '\n';
    }

    return 0;
}