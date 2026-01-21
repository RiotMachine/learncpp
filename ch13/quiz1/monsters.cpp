#include <iostream>
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

    std::ostream& operator<<(std::ostream& o, Type t)
    {
        switch(t)
        {
        case (ogre):        return o << "Ogre";
        case (dragon):      return o << "Dragon";
        case (orc):         return o << "Orc";
        case (giantSpider): return o << "Giant Spider";
        case (slime):       return o << "Slime";
        default:            return o << "???";
        }
    }

    struct Monster
    {
        Type type{ };
        std::string name{ };
        int health{ 100 };
    };

    void printMonster(const Monster& monster)
    {
        std::cout << "This " << monster.type << " is named " << monster.name
            << " and has " << monster.health << " health.\n";
    }
}
