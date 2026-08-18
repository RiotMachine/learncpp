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
    void play();
    void printResults();

private:
    enum Option
    {
        run,
        fight,
        max_options
    };

    // return whether encounter with Creature is ongoing
    using Action = bool(Game::*)(Monster&);

    Game(std::string_view userName)
      : m_player{ userName } {}

    Action choosePlayerAction();
    bool player_runFrom(Monster&);
    bool player_fight(Monster&);

    constexpr static std::array<Action, max_options> playerActions{
        &Game::player_runFrom,
        &Game::player_fight
    };

    Player m_player;
};

#endif
