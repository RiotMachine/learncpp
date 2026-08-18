#include "IOHelper.h"
#include "MonsterGame.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>
#include <string>


MonsterGame MonsterGame::init()
{
    std::cout << "Enter your name: ";
    std::string userName{ IOHelper::getString() };
    std::cout << "Welcome, " << userName << '\n';
    return MonsterGame { Player { userName } };
}

void MonsterGame::play()
{
    while (m_user.isAlive() && !m_user.hasWon())
    {
        Monster monster{ Monster::getRandomMonster() };
        std::cout << "You have encountered a " << monster.name() << ".\n";
        bool inEncounter{ true };
        while (inEncounter)
        {
            inEncounter = chooseResponse(monster);
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

void MonsterGame::printResults()
{
    if (m_user.hasWon())
        std::cout << "You won with " << m_user.gold() << " gold!";
    else
        std::cout << "You died at level " << m_user.level()
                  << " and with " << m_user.gold() 
                  << " gold.\nToo bad you can't take it with you!";
}