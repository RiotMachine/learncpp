// pass by lvalue reference

#include <iostream>

void increment(int y, int& z)
{
    ++y;
    ++z;
}

int main()
{
    int x{ 2 };
    int xx{ 4 };
    increment(x, xx);
    std::cout << x << '\t' << xx << '\n';

    return 0;
}
