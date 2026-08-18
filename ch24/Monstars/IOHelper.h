#ifndef IOHELPER_H
#define IOHELPER_H

#include <cctype>
#include <iostream>
#include <limits>
#include <string>

namespace IOHelper
{
    inline void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline char lowerCase(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    inline char getChar()
    {
        char c{ };
        std::cin >> c;
        clearBuffer();
        return c;
    }

    inline std::string getString()
    {
        std::string str;
        std::getline(std::cin >> std::ws, str);
        return str;
    }
}

#endif
