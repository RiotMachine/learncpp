#ifndef MONSTERS_H
#define MONSTERS_H

#include <iosfwd>
#include <string>

namespace Monsters
{
    enum Type
    {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime,
    };

    std::ostream& operator<<(std::ostream& o, Type t);

    struct Monster
    {
        Type type{ };
        std::string name{ };
        int health{ 100 };
    };

    void printMonster(const Monster& monster);
}

#endif
