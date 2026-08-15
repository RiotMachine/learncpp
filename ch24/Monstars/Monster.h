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
    Monster(std::string_view str, char c, int x, int y, int z)
      : Creature(str, c, x, y, z) {}

    const static std::array<Monster, max_types> monsters;
};


const inline std::array<Monster, Monster::max_types> Monster::monsters{{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
}};

#endif
