#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <array>

template <std::size_t N>
struct Player
{
    std::string name{ };
    int gold{ };
    std::array<int, N> inventory{ };
};

#endif