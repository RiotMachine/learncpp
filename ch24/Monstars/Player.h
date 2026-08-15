#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <string_view>

class Player : public Creature
{
public:
    Player(std::string_view name)
      : Creature(name, '@', 10, 1, 0) {}

    int level() const { return m_level; };

    bool hasWon() const { return m_level > 19; }
    void levelUp()      { ++m_level; addDamage(1); }

private:
    int m_level{ 1 };
};

#endif
