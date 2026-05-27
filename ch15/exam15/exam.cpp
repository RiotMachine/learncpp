#include "Monster.h"
#include "random.h"
#include <iostream>
#include <string_view>

namespace MonsterGenerator
{
    int constexpr maxName{ 5 };
    int constexpr maxRoar{ 5 };
    int constexpr maxXP{ 100 };

    std::string_view getName(int x)
    {
        switch (x)
        {
        case 0:  return "Blarg";
        case 1:  return "Carey";
        case 2:  return "Marc";
        case 3:  return "Toney";
        case 4:  return "Mikael";
        case 5:  return "Towanda";
        default: return "???";
        }
    }

    std::string_view getRoar(int x)
    {
        switch (x)
        {
        case 0:  return "*ROAR*";
        case 1:  return "*meow*";
        case 2:  return "*tanks*";
        case 3:  return "*shining violence*";
        case 4:  return "*why?*";
        case 5:  return "*no*";
        default: return "???";
        }
    }

    Monster generate()
    {
        return Monster{
            static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes-1)),
            getName(Random::get(0, maxName)),
            getRoar(Random::get(0, maxRoar)),
            Random::get(1, maxXP)
            };
    }
}

int main()
{
    std::cout << '\n';
    Monster m{ MonsterGenerator::generate() };
    m.print();

    return 0;
}
