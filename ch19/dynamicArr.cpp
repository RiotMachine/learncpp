#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using Idx = std::size_t;

int main()
{
    std::cout << "How many names would you like to enter? ";
    Idx length;
    std::cin >> length;

    auto* names{ new std::string[length] };
    for (Idx i{ 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i+1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names+length);

    std::cout << "\nHere is your sorted list:\n";
    for (Idx i{ 0 }; i < length; ++i)
        std::cout << "Name #" << i+1 << ": " << names[i] << '\n';

    // superfluous, but practice
    delete[] names;
    names = nullptr;

    return 0;
}
