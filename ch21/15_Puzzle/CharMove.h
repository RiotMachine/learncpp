#ifndef CHARMOVE_H
#define CHARMOVE_H

#include <string_view>

namespace CharMove
{
    enum Type
    {
        left  = 'a',
        right = 'd',
        up    = 'w',
        down  = 's',
        reset = 'r',
        quit  = 'q'
    };
    constexpr static std::string_view str{ "adwsrq" };
    constexpr static std::string_view menu{
        "a - left\n"
        "d - right\n"
        "w - up\n"
        "s - down\n
        "r - reset\n"
        "q - quit"
    };
}