#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "Random.h"
#include <array>

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

    static Monster getRandomMonster()
    {
        return monsters[Random::get(0, max_types-1)];
    }

private:
    Monster(std::string_view name, int health, int damage, int gold)
      : Creature(name, health, damage, gold) {}

    const static std::array<Monster, max_types> monsters;
};


const inline std::array<Monster, Monster::max_types> Monster::monsters{{
    { "dragon", 20, 4, 100 },
    { "orc",    4, 2, 25 },
    { "slime",  1, 1, 10 }
}};

#endif
