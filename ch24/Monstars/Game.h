#ifndef GAME_H
#define GAME_H

#include "Monster.h"
#include "Player.h"
#include <array>
#include <string_view>

class Game
{
public:
    static Game init();
    bool play();
    void printResults();

private:
    enum Option
    {
        Run,
        Fight,
        max_options
    }

    Game(std::string_view userName)
      : m_player{ userName } {}

    Option chooseOption();
    // return whether encounter with Monster is ongoing
    bool runFrom(Monster);
    bool fight(Monster);

    constexpr static std::array<void(*)(Monster), max_options> options{
        runFrom, fight
    };

    static_assert(max_options == options.size());

    Player m_player{ };
};

#endif
