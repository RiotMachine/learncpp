// dereferencing nullptr to crash exe

#include <iostream>

int main()
{
    int x{ 7 };
    int* ptr = &x;
    ptr = nullptr;
    std::cout << *ptr;

    return 0;
}
