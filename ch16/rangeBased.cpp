#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
bool search(const std::vector<T>& arr, T desire)
{
    for (const auto& x : arr)
        if (x == desire)
            return true;
    return false;
}

std::string getName()
{
    std::cout << "Enter a name: ";
    std::string input{};
    std::cin >> input;
    return input;
}


int main()
{
    std::vector<std::string_view> names{
        "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"
        };

    std::string desName{ getName() };

    std::cout << desName << " was " << (
        search(
            names, static_cast<std::string_view>(desName)
            ) ? "found.\n" : "not found.\n"
        );

    return 0;
}
