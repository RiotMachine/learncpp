#include <cctype>   // for std::tolower
#include <iostream>
#include <limits>

using IDX = std::size_t;

void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char lowercase(char c)
{
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}
