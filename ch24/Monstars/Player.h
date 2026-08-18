#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <string_view>

class Player : public Creature
{
public:
    explicit Player(std::string_view name, int health=10, int damage=1, int gold=0)
      : Creature(name, health, damage, gold) {}

    int level() const { return m_level; }

    bool hasWon() const { return m_level > 19; }
    void levelUp()      { ++m_level; addDamage(1); }

private:
    int m_level{ 1 };
};

#endif
