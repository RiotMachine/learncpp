// pass by const lvalue reference

#include <iostream>

void increment(int& y, const int& z)
{
    ++y;
    // ++z not allowed
}

void print(const int& z)
{
    std::cout << z << '\n';
}

int main()
{
    int x{ 2 };
    int xx{ 4 };
    increment(x, xx);

    // pass by const lvalue can handle modable lvalues, const lvalues,
    // and rvalues
    const int xxx{ 6 };
    print(x);
    print(xxx);
    print(8);

    // pass by reference is often used when you dont want to create an expensive copy
    // make sure the ref type matches the argument type so an addit expensive
    /// temp object isnt created
    // print('a') would first result in a conversion to a temp int object

    return 0;
}
