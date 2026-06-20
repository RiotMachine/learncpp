#include <array>
#include <functional> // for std::reference_wrapper
#include <iostream>

void print(int x) { std::cout << "int equals " << x << '\n'; }

int main()
{
    int x{ 3 };
    int y{ 8 };

    int& xRef{ x };
    int& yRef{ y };

    // CTAD deduces std::array<int, 2>
    std::array basicArr{ xRef, yRef };
    basicArr[1] = 7;
    print(y); // still prints 8

    // std::array of references is not allowed
    // std::reference_wrapper is a workaround
    std::array<std::reference_wrapper<int>, 2> arr{ x, y };
    arr[1].get() = 7;
    // both print 7
    print(y);
    print(arr[1]);

    // std::ref() and std::cref are less-verbose ways to init a reference_wrapper
    auto ref{ std::ref(x) };
    ref.get() = 10;
    print(x); // x is now 10

    return 0;
}
