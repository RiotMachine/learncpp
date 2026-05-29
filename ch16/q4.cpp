#include <iostream>
#include <vector>

template <typename T>
void printElement(const std::vector<T>& v, int input)
{
    std::size_t idx{ static_cast<std::size_t>(input) };

    if (input >= 0 && idx < v.size())
        std::cout << "The element has value " << v[idx] << '\n';
    else
        std::cout << "Invalid index\n";
}


int main()
{
    std::vector v1{ 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2{ 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
