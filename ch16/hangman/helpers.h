#ifndef HELPERS_H
#define HELPERS_H

#include <cctype>   // for std::tolower
#include <iostream>
#include <limits>

namespace Helper
{
    using IDX = std::size_t;

    inline void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline char lowercase(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
}

#endif
