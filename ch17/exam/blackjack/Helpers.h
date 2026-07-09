#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>

namespace Helpers
{
    inline void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline char getChar()
    {
        char c{ };
        while (!(std::cin >> c))
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return c;
    }
}

#endif
