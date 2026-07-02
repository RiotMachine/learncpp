// emulating Alex's indexing-by-enum focus

#include "Helpers.h"
#include "Player.h"
#include "Potion.h"
#include "Random.h"
#include <iostream>

Potion::Game Potion::Game::setup()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n"
        << "Enter your name: ";
    Player<max_types> player{ 
        Helpers::getWord(),
        Random::get(s_minGold, s_maxGold), 
    };
    std::cout << "Hello, " << player.name << ", you have "
        << player.gold << " gold.";
    return Game { player };
}

void Potion::Game::play()
{
    while (true)
    {
        std::cout << '\n';
        printMenu();
        std::cout << "Enter the number of the potion you'd like to buy, "
            << "or 'q' to quit: ";

        bool validInput{ false };
        while (!validInput)
        {
            char input{ Helpers::getChar() };
            if (input == 'q')
                return;

            // printMenu offset int casts of Type by +1
            int selection{ input - '0' - 1 };
            for (const auto& type : types)
            {
                if (static_cast<int>(type) == selection)
                {
                    validInput = true;
                    const Data& potion{ data[type] };
                    if (m_player.gold < potion.cost)
                        std::cout << "You cannot afford that.\n";
                    else
                    { 
                        ++m_player.inventory[type];
                        m_player.gold -= potion.cost;
                        std::cout << "You purchased a potion of " << potion.name
                            << ". You have " << m_player.gold << " gold left.\n";
                    }
                    break;
                }
            }
            if (!validInput)
                std::cout << "That is an invalid input. Try again: ";
        }
    }
}

void Potion::Game::close()
{
    std::cout << "Your inventory contains:\n";
    for (const auto& type : types)
    {
        if (m_player.inventory[type] != 0)
            std::cout << m_player.inventory[type] << "x potion of "
                << data[type].name << '\n';
    }
    std::cout << "You escaped with " << m_player.gold << " gold remaining.\n\n"
        << "Thanks for shopping at Roscoe's potion emporium!";
}

void Potion::printMenu()
{
    std::cout << "Here is our selection for today:\n";
    for (const auto& type : types)
    {
        const Data& potion{ data[type] };
        std::cout << static_cast<int>(type)+1 << ") " 
            << potion.name << " costs " << potion.cost << '\n';
    }
}