// emulating Alex's indexing-by-enum focus

#include "Helpers.h"
#include "Potion.h"
#include <iostream>

void Potion::printMenu()
{
    std::cout << "Here is our selection for today:\n";
    for (const auto& e : potions)
        std::cout << static_cast<int>(e.type)+1 << ") " 
            << e.name << " costs " << e.cost << '\n';
}

void Potion::Game::setup()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n"
        << "Enter your name: ";
    m_player.name = Helpers::getWord();
    std::cout << "Hello, " << m_player.name << ", you have "
        << m_player.gold << " gold.";
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

            // ::printMenu offsets int casts of .type by +1
            // char arithmetic promotes char to signed int
            int selection{ input - '0' - 1 };
            for (const auto& potion : potions)
            {
                if (static_cast<int>(potion.type) == selection)
                {
                    validInput = true;
                    if (m_player.gold < potion.cost)
                        std::cout << "You cannot afford that.\n";
                    else
                    { 
                        ++m_player.inventory[potion.type];
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
    for (const auto& potion : potions)
    {
        if (m_player.inventory[potion.type] != 0)
            std::cout << m_player.inventory[potion.type] << "x potion of "
                << potion.name << '\n';
    }
    std::cout << "You escaped with " << m_player.gold << " gold remaining.\n\n"
        << "Thanks for shopping at Roscoe's potion emporium!";
}
