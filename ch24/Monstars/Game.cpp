#include "Game.h"

std::string Game::getName()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    return name;
}

bool fight(Monster m)
{
    std::cout << "You have encountered a " << m.name() << ".\n";

    while (
}

bool Game::play()
{
    std::string playerName { getName() };
    Game game{ playerName };

    std::cout << "Welcome, " << game.player.name();

    while (!m_player.isDead() && !m_player.hasWon())
    {
        Choice choice
}

