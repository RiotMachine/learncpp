#include <iostream>
#include <vector>

struct Answers
{
    // no CTAD w/in a class type
    std::vector<int> squares{ 1, 4, 9, 16, 25 };

    // list constructor creates vector with single int 5
    std::vector<int> q2a{ 5 };

    // non-list constructor creates vector with 5 value-init ints
    // direct init not allowed for member default
    std::vector<int> q2b{ std::vector<int>(5) };

    // daily high temp to tenth of a degree
    std::vector<float> highs{ std::vector<float>(365) };
};

std::vector<int> getIntVector(int x)
{
    std::cout << "Enter " << x << " integers: ";
    std::vector<int> v(x);
    for (int i{ 0 }; i < x; ++i)
        std::cin >> v[i];
    return v;
}

int getSum(const std::vector<int>& v)
{
    int sum{ 0 };
    for (int i{ 0 }; i < v.size(); ++i)
        sum += v[i];
    return sum;
}

int getProduct(const std::vector<int>& v)
{
    int product{ 1 };
    for (int i{ 0 }; i < v.size(); ++i)
        product *= v[i];
    return product;
}

int main()
{
    std::vector v{ getIntVector(3) };
    std::cout << "The sum is: " << getSum(v) << '\n';
    std::cout << "The product is: " << getProduct(v) << '\n';

    return 0;
}
