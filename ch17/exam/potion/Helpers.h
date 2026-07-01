#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>
#include <string>

namespace Helpers
{
    void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>:: max(), '\n');
    }

    char getChar()
    {
        char c{ };
        while (!std::cin >> c)
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return c;
    }

    std::string getStr()
    {
        std::string str{ };
        while (!std::cin >> str)
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return str;
    }
}

#endif