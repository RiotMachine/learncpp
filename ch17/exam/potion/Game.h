#ifndef GAME_H
#define GAME_H

#include "Potion.h"
#include "Random.h"
#include <string>
#include <vector>

class Game
{
public:
    void setup();
    void play();
    void close();

private:
    struct Player
    {
        std::string name{ };
        int gold{ Random::get(s_minGold, s_maxGold) };
        std::vector<int> inventory{ std::vector<int>(Potion::max_types) };
    };

    static constexpr int s_minGold{ 80 };
    static constexpr int s_maxGold{ 120 };

    Player m_player{ };
};

#endif
