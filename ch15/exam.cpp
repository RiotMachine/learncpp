#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };

    Monster(Type t, std::string_view name, std::string_view roar, int xp)
        : m_type{ t }, m_name{ name }, m_roar{ roar }, m_hitPoints{ xp } {}

    void print();

private:
    Type m_type{ };
    std::string m_name{ };
    std::string m_roar{ };
    int m_hitPoints{ };
};

std::string_view getTypeString(const Monster::Type& m)
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

void Monster::print()
{
    std::cout << m_name << " the " << getTypeString(m_type);
    if (m_hitPoints > 0)
        std::cout << " has " << m_hitPoints << " hit points and says "
            << m_roar << ".";
    else
        std::cout << " is dead.";
    std::cout << '\n';
}


int main()
{
    Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
    vampire.print();

    return 0;
}
