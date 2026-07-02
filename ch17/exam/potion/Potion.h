// Namespace for potion data and its related game

#ifndef POTION_H
#define POTION_H

#include "Player.h"
#include <array>
#include <string_view>

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
        std::string_view name{ };
        int cost{ };
    };

    class Game
    {
    public:
        static constexpr int s_minGold{ 80 };
        static constexpr int s_maxGold{ 120 };

        static Game setup();
        void play();
        void close();

    private:
        Game (Player<max_types> p)
            : m_player{ p } {}
        Player<max_types> m_player{ };
    };

    inline constexpr std::array types{
        healing, mana, speed, invisibility
    };

    inline constexpr std::array data{
        Data { "healing", 20 },
        Data { "mana", 30 },
        Data { "speed", 12 },
        Data { "invisibility", 50 }
    };

    static_assert(types.size() == max_types);
    static_assert(data.size() == max_types);

    void printMenu();
}

#endif