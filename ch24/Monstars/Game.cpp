#include "Game.h"
#include "IOHelper.h"
#include "Monster.h"
#include "Random.h"
#include <iostream>
#include <map>
#include <string>

// public

Game Game::init()
{
    std::cout << "Enter your name: ";
    std::string userName{ IOHelper::getString() };
    std::cout << "Welcome, " << userName << '\n';
    return Game { userName };
}

void Game::play()
{
    while (m_player.isAlive() && !m_player.hasWon())
    {
        Monster monster{ Monster::getRandomMonster() };
        std::cout << "You have encountered a " << monster.name() << ".\n";
        bool inEncounter{ true };
        while (inEncounter)
        {
            Action action{ choosePlayerAction() };
            inEncounter = action(monster);
            std::cout << '\n';
        }
    }
}

void Game::printResults()
{
    if (m_player.hasWon())
        std::cout << "You won with " << m_player.gold() << " gold!";
    else
        std::cout << "You died at level " << m_player.level()
                  << " and with " << m_player.gold()
                  << ".\nToo bad you can't take it with you!";
}


// private
Game::Action Game::choosePlayerAction()
{
    while (true)
    {
        std::cout << "(R)un or (F)ight: ";
        char c{ IOHelper::getChar() };
        c = IOHelper::lowerCase(c);
        switch (c)
        {
        case 'r': return playerActions[run];
        case 'f': return playerActions[fight];
        }
        std::cout << "Invalid input.\n";
    }
}

bool Game::player_runFrom(Monster monster)
{
    // 50% chance usr escapes
    int x{ Random::get(0,1) };
    if (x == 0)
    {
        m_player.reduceHealth(monster.damage());
        std::cout << "You failed to flee.\n The " << monster.name()
                  << " hit you for " << monster.damage() << '.';
        return m_player.isAlive();
    }
    else
    {
        std::cout << "You successfully fled.";
        return false;
    }
}

bool Game::player_fight(Monster monster)
{
    monster.reduceHealth(m_player.damage());
    std::cout << "You hit the " << monster.name() << " for "
              << m_player.damage() << ".\n";

    if (!monster.isAlive())
    {
        m_player.levelUp();
        std::cout << "You killed the " << monster.name()
                  << ".\n You are now level " << m_player.level()
                  << ".\n You found " << monster.gold() << " gold.";
        return false;
    }

    m_player.reduceHealth(monster.damage());
    std::cout << "The " << monster.name() << " hit you for "
              << monster.damage() << " damage.";
    return m_player.isAlive();
}
