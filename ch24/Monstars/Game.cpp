#include "Game.h"
#include "IOHelper.h"
#include "Random.h"

// public

Game Game::init()
{
    std::cout << "Enter your name: ";
    std::string userName{ IOHelper::getString() };
    std::cout << "Welcome, " << userName << '\n';
    return Game{ userName };
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


// private

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


// related non-members

std::ostream& operator<<(std::ostream& out, const Game::Option option)
{
    switch (option)
    {
    case Run  : return "(R)un";
    case Fight: return "(F)ight";
    default   : return out << "???"
    }
}

std::optional<Game::Option> getChoiceFromChar(char c)
{
    c = IOHelper::lowerCase(c);
    switch (c)
    {
    case r: return Game::Run;
    case f: return Game::Fight;
    }

    return {};
}

std::istream& operator>>(std::istream& in, Game::Option option)
{
    char c{ };
    in >> c;
    std::optional<Game::Option> choice{ getChoiceFromChar(c) };

    if (choice)
    {
        option = *choice;
        return in;
    }
    in.setstate(std::ios_base::failbit);
    option = max_options;
    return in;
}
