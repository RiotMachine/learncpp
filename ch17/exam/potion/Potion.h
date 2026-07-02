// Namespace for potion data and its related game

#ifndef POTION_H
#define POTION_H

#include "Random.h"
#include <array>
#include <string>
#include <string_view>
#include <vector>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_types
    };

    struct Data
    {
        Type type{ };
        std::string_view name{ };
        int cost{ };
    };

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
            std::vector<int> inventory{ std::vector<int>(max_types) };
        };

        static constexpr int s_minGold{ 80 };
        static constexpr int s_maxGold{ 120 };

        Player m_player{ };
    };

    constexpr std::array potions{
        Data { healing, "healing", 20 },
        Data { mana, "mana", 30 },
        Data { speed, "speed", 12 },
        Data { invisibility, "invisibility", 50 }
    };

    static_assert(potions.size() == max_types);

    void printMenu();
}

#endif