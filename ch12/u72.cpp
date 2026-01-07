// pointer & lvalue reference similarities

#include <iostream>

template <typename T>
void print(T x, T& ref, T* ptr)
{
    std::cout << x << '\t' << ref << '\t' << *ptr << '\n';
}

int main()
{
    double x{ 1.5 };
    double& ref{ x };
    double* ptr{ &x };
    print(x, ref, ptr);

    ref = 6;
    print(x, ref, ptr);

    *ptr = 7;
    print(x, ref, ptr);

    return 0;
}
