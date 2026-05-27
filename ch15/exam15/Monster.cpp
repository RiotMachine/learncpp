#include "Monster.h"
#include <string_view>

constexpr std::string_view getTypeString(const Monster::Type& m)
{
    switch (m)
    {
    case Monster::dragon:
        return "dragon";
    case Monster::goblin:
        return "goblin";
    case Monster::ogre:
        return "ogre";
    case Monster::orc:
        return "orc";
    case Monster::skeleton:
        return "skeleton";
    case Monster::troll:
        return "troll";
    case Monster::vampire:
        return "vampire";
    case Monster::zombie:
        return "zombie";
    default:
        return "???";
    }
}

void Monster::print() const
{
    std::cout << m_name << " the " << getTypeString(m_type);
    if (m_hitPoints > 0)
        std::cout << " has " << m_hitPoints << " hit points and says "
            << m_roar << ".";
    else
        std::cout << " is dead.";
    std::cout << '\n';
}

