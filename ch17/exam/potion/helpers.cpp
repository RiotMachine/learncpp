#include <iostream>
#include <limits>

namespace Helpers
{
    void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>:: max(), '\n');
    }

    int getInt()
    {
        int x{ };
        while (!std::cin >> x)
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return x;
    }
}
