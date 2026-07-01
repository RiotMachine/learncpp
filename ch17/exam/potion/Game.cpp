#include "Game.h"
#include "Helpers.h"
#include "Potion.h"
#include "Random.h"
#include <iostream>

void setup()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n" 
        << "Enter your name: ";
    m_player.name = Helpers::getStr();
    m_player.gold = Random::get(s_minGold, s_maxGold);
    std::cout << "Hello, " << m_player.name << ", you have "
        << m_player.gold << " gold.";
}

void play()
{
    std::cout << '\n';
    Potion::printMenu();
    std::cout << "Enter the number of the potion you'd like to buy,"
        << "or 'q' to quit: ";

    while (true)
    {
        char selection{ Helpers::getChar() };
        if (selection == 'q')
            break;
        // ascii offset to get int
        selection -= '0';
        if (selection > 0 && selection <= Potion::max_types)
        {
            const Potion::Data& potion{ Potion::potions[selection] };
            if (m_player.gold >= potion.cost)
            { 
                ++m_player.inventory[selection];
                m_player.gold -= potion.cost;
                std::cout << "You purchased a potion of " << potion.name
                    << " You have " << m_player.gold << " gold left.\n";
            }
            else
                std::cout << "You cannot afford that.\n";
        }
        else
            std::cout << "That is an invalid input. Try again: ";
    }
}

void close()
{
    std::cout << "Your inventory contains:\n";
    for (int i{ 0 }; i < inventory.size(); ++i)
    {
        if (inventory[i] != 0)
        {
            const Potion::Data& potion{ Potion::potions[i] };
            std::cout << inventory[i] << "x potion of " << potion.name << '\n';
        }
    }
    std::cout << "You escaped with " << m_player.gold << " remaining.\n\n"
        << "Thanks for shopping at Roscoe's potion emporium!";
}
