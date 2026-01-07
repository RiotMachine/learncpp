// pointer, address-of, and dereference syntax

#include <iostream>

int main()
{
    int x{ 10 };
    int* ptr{ &x };
    std::cout << *ptr << '\n';

    int y{ 20 };
    ptr = &y;
    std::cout << *ptr << '\n';

    *ptr = 21;
    std::cout << y << '\n';

    return 0;
}
