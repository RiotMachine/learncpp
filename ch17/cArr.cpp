#include <iostream>

namespace Q1
{
    constexpr int a[3]{ };
}

namespace Q2
{
    int length{ 5 };

    /* length is not a compile-time constant
    const int arr[length]{ 9, 7, 5, 3, 1 };
    
    arr[length] accesses out-of-bounds element
    arr[length];
    
    cannot assign value to element of const array
    arr[0] = 4; */
}

template <typename T, typename Array>
bool searchArr(const T& obj, const Array& arr)
{
    for (const T& x : arr)
    {
        if (x == obj)
            return true;
    }
    return false;
}

int main()
{
    constexpr int squares[]{ 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };

    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int input{ };
        std::cin >> input;
        if (input == -1)
            break;
        bool isSquare = searchArr(input, squares);
        std::cout << input << (isSquare ? " is " : " is not ") << "a perfect square\n\n"; 
    }

    std::cout << "Bye\n";
    return 0;
}