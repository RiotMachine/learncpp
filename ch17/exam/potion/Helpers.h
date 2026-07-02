#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>
#include <string>

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

    // returns input up to first whitespace
    inline std::string getWord()
    {
        std::string str{ };
        while (!(std::cin >> str))
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return str;
    }
}

#endif
