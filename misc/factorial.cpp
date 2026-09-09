#include <iostream>

int factorial(int start)
{
    if (start < 1)
        return 0;
    else if (start == 1)
        return start;
    else
        return start * factorial(start-1);
}

int main()
{
    constexpr int top{ 10 };
    for (int i{ }; i < top; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';

    return 0;
}
