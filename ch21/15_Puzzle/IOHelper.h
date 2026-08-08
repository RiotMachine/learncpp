#ifndef IOHELPER_H
#define IOHELPER_H

#include <iostream>
#include <limits>
#include <string_view>

namespace IOHelper
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

    inline int getInt(std::string_view sv)
    {
        int x{ };
        while (true)
        {
            std::cout << sv;
            if (std::cin >> x)
            {
                clearBuffer();
                return x;
            }
            std::cin.clear();
            clearBuffer();
        }
    }

    // thanks qbert220
    // https://stackoverflow.com/a/18822888
    class OStreamSaver
    {
    public:
        explicit OStreamSaver(std::ostream& out)
        :  m_out{ out }, m_flags{ out.flags() } {}

        OStreamSaver(const OStreamSaver& oss) = delete;

        OStreamSaver& operator=(const OStreamSaver& oss) = delete;

        ~OStreamSaver() { m_out.flags(m_flags); }

    private:
        std::ostream& m_out;
        std::ios::fmtflags m_flags;
    };
}

#endif