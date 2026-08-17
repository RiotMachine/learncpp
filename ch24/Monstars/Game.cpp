#include "Game.h"
#include "Random.h"

char getChar()
{

}

std::string getString()
{

}

Game Game::init()
{
    std::string userName{ getString("Enter your name: ") };
    std::cout << "Welcome, " << userName << '\n';
    return Game{ userName };
}

bool Game::play()
{
    while (m_player.isAlive() && !m_player.hasWon())
    {
        Monster monster{ Monster::getRandomMonster() };
        std::cout << "You have encountered a " << monster.name() << ".\n";
        bool inEncounter{ true };
        while (inEncounter)
        {
            Option action{ chooseOption() };
            inEncounter = options[action](monster);
            std::cout << '\n';
        }
    }
}

void Game::printResults(
{
    if (m_player.hasWon())
        std::cout << "You won with " << m_player.gold() << " gold!"
    else
        std::cout << "You died at level " << m_player.level()
                  << " and with " << m_player.gold()
                  << ".\nToo bad you can't take it with you!";
}

Game::option Game::chooseOption()
{

}

bool Game::runFrom(Monster monster)
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

bool Game::fight(Monster monster)
{
    monster.reduceHealth(m_player.damage());
    std::cout << "You hit the " << monster.name() << " for "
              << m_player.damage() << ".\n"
    if (!monster.isAlive())
    {
        std::cout << "You killed the " << monster.name() << '.';
        return false;
    }
    m_player.reduceHealth(monster.damage());
    std::cout << "The " << monster.name() << " hit you for "
              << monster.damage() << " damage.";
    return m_player.isAlive();
}
