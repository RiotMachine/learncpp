// non-type template parameters
/// good way to pass a constexpr as a parameter
/// in a type template parameter, the template is for type selections
/// in a non-type template parameter, the template is for a constexpr value

#include <iostream>

template <int N>
constexpr int factorial()
{
    static_assert(N >= 0, "factorial<N>: N must be non-negative");

    int product{1};
    for (int i{N}; i > 1; --i)
    {
        product *= i;
    }
    return product;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // factorial<-3>(); // should fail to compile

    return 0;
}