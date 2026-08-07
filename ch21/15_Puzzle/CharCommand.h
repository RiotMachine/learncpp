#ifndef CHARCOMMAND_H
#define CHARCOMMAND_H

#include <array>
#include <iostream>
#include <string_view>

namespace CharCommand
{
    enum Command : char
    {
        left  = 'a',
        right = 'd',
        up    = 'w',
        down  = 's',
        reset = 'r',
        quit  = 'q'
    };
    constexpr inline std::string_view str{ "adwsrq" };
    constexpr inline std::array commands{
        left, right, up, down, reset, quit
    };
    static_assert(str.size() == commands.size());

    constexpr inline std::array moves{
        left, right, up, down
    };

    inline bool isCommand(char c) { return str.find(c) != std::string_view::npos; }

    inline std::ostream& operator<<(std::ostream& out, Command option)
    {
        out << static_cast<char>(option) << " - ";
        switch (option)
        {
        case left:
            return out << "left";
        case right:
            return out << "right";
        case up:
            return out << "up";
        case down:
            return out << "down";
        case reset:
            return out << "reset";
        case quit:
            return out << "quit";
        default:
            return out << "???";
        }
    }
}

#endif