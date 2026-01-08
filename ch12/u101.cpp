#include <iostream>

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2)
{
    ++(*ptr2);
    ptr2 = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "x is " << x << "\tptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "x is " << x << "\tptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
