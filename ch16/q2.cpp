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

void fillVector(std::vector<int>& v)
{
    std::cout << "Enter " << v.size() << " integers: ";
    for (int i{ 0 }; i < v.size() ; ++i)
        std::cin >> v[i];
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
    int product{ v.empty() ? 0 : 1 };
    for (int i{ 0 }; i < v.size(); ++i)
        product *= v[i];
    return product;
}

int main()
{
    std::vector<int> v(3);
    fillVector(v);
    std::cout << "The sum is: " << getSum(v) << '\n';
    std::cout << "The product is: " << getProduct(v) << '\n';

    return 0;
}
