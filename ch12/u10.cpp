// pass by address syntax

#include <iostream>

template <typename T>
void passByValue(T x)
{
    std::cout << x << " passed by value\n";
}

template <typename T>
void passByRef(const T& ref)
{
    std::cout << ref << " passed by reference (lvalue overload)\n";
}

template <typename T>
void passByRef(const T&& ref)
{
    std::cout << ref << " passed by reference (rvalue overload)\n";
}

template <typename T>
void passByAddress(const T* ptr)
{
    if(!ptr)
    {
        std::cout << "\nnull pointer!\n";
        return;
    }
    std::cout << *ptr << " passed by address\n";
}

int main()
{
    char x{ 'b' };
    std::cout << "value at " << static_cast<const void*>(&x) << '\n';
    passByValue(x);
    passByRef(x);
    passByAddress(&x);

    char& ref{ x };
    std::cout << "\nvalue at " << static_cast<const void*>(&ref) << '\n';
    passByValue(ref);
    passByRef(ref);
    passByAddress(&ref);

    std::cout << '\n';
    passByValue('b');
    passByRef('b');

    char* ptr{ &x };
    std::cout << "\nvalue at " << static_cast<const void*>(ptr) << '\n';
    passByValue(*ptr);
    passByRef(*ptr);
    passByAddress(ptr);

    ptr = nullptr;
    passByAddress(ptr);

    return 0;
}
