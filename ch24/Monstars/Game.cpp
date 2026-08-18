#include "Creature.h"
#include "Game.h"
#include "IOHelper.h"
#include "Random.h"
#include <iostream>

bool Game::chooseResponse(Creature& creature)
{
    while (true)
    {
        std::cout << "(R)un or (F)ight: ";
        char c{ IOHelper::getChar() };
        c = IOHelper::lowerCase(c);
        switch (c)
        {
        case 'r': return flee(creature);
        case 'f': return fight(creature);
        }
        std::cout << "Invalid input.\n";
    }
}

bool Game::flee(const Creature& creature)
{
    // 50% chance user escapes
    int x{ Random::get(0,99) };

    if (x % 2 == 0)
    {
        creature.attack(m_user);
        std::cout << "You failed to flee.\nThe " << creature.name()
                  << " hit you for " << creature.damage() << " damage.";
        return m_user.isAlive();
    }

    std::cout << "You successfully fled.";
    return false;
}

bool Game::fight(Creature& creature)
{
    m_user.attack(creature);
    std::cout << "You hit the " << creature.name() << " for "
              << m_user.damage() << " damage.\n";

    if (!creature.isAlive())
    {
        m_user.levelUp();
        m_user.addGold(creature.gold());
        std::cout << "You killed the " << creature.name()
                  << ".\nYou are now level " << m_user.level()
                  << ".\nYou found " << creature.gold() << " gold.";
        return false;
    }

    creature.attack(m_user);
    std::cout << "The " << creature.name() << " hit you for "
              << creature.damage() << " damage.";
    return m_user.isAlive();
}
