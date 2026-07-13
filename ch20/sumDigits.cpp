#include <cassert>
#include <iostream>

int sumDig(int x)
{
    assert (x >= 0);
    if (x < 10)
        return x;
    return sumDig(x / 10) + (x % 10);
}

int main()
{
    constexpr int NUM{ 93427 };
    std::cout << "The sum of the digits of " << NUM 
        << " is " << sumDig(NUM) << ".\n";

    return 0;
}