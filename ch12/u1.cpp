// lvalues and rvalues
/// lvalues are identifiable and persist
/// rvalues eval to a value and have to be used immediately

#include <iostream>

template <typename T>
constexpr bool is_lvalue(T&)
{
    return true;
}

template <typename T>
constexpr bool is_lvalue(T&&)
{
    return false;
}

#define PRINTVCAT(expr) { std::cout << #expr " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }

int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 is an rvalue
    const double d{ 1.2 }; // 1.2 is an rvalue

    int y{ x }; // x is a modifiable lvalue
    const double e{ d }; // d is a non-modifiable lvalue
    int z{ return5() }; // return5() is an rvalue (since the result is returned by value)

    int w{ x+1 }; // x + 1 is an rvalue
    int q{ static_cast<int>(d) }; // static_cast<int>(d) is an rvalue

    PRINTVCAT(5);
    PRINTVCAT(1.2);
    PRINTVCAT(x);
    PRINTVCAT(d);
    PRINTVCAT(return5());
    PRINTVCAT(x+1);
    PRINTVCAT(static_cast<int>(d));

    return 0;
}
