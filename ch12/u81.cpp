// using nullptr as boolean value

#include <iostream>

template <typename T>
void print(T* ptr)
{
    // n.b. dangling ptr would still eval as true
    if (ptr)
        std::cout << "ptr is not null\n";
    else
        std::cout << "ptr is null\n";
}

int main()
{
    int x{ 10 };
    int* ptr{ &x };
    print(ptr);

    ptr = nullptr;
    print(ptr);

    return 0;
}
