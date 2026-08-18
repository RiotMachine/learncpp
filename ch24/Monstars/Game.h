#ifndef GAME_H
#define GAME_H

#include "Creature.h"
#include "Player.h"
#include <vector>

/*
  Game prototype where current Player takes actions 
  relative to some Creature
*/

class Game
{
protected:
    enum class Option
    {
        flee,
        fight,
        max_options
    };

    Game(const Player& p)
      : m_user{ p } {}

    // return whether encounter with Creature is ongoing
    bool chooseResponse(Creature&);
    bool flee(const Creature&);
    bool fight(Creature&);

    Player m_user;
};

#endif
