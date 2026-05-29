#include <iostream>
#include <vector>

std::vector<int> fillVector(int x)
{
    std::vector<int> v(x);
    std::cout << "Enter " << x << " integers: ";
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
    int product{ v.empty() ? 0 : 1 };
    for (int i{ 0 }; i < v.size(); ++i)
        product *= v[i];
    return product;
}

int main()
{
    // since std::vector supports move semantics
    /// returned vector is moved instead of copied into v if elision doesnt occur
    /// so return by value is best
    std::vector v{ fillVector(3) };
    std::cout << "The sum is: " << getSum(v) << '\n';
    std::cout << "The product is: " << getProduct(v) << '\n';

    return 0;
}
