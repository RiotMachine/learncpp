#include "Game.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

Game Game::setup()
{
    std::cout << "Start where? ";
    int start;
    std::cin >> start;

    std::cout << "How many numbers? ";
    int length;
    std::cin >> length;

    return Game {start, length};
}

bool Game::play()
{
    std::cout << "I generated " << m_length << " numbers.\n"
        << "Do you know each square multiplied by " << m_multiplier << "?\n";

    while (remaining())
    {
        std::cout << remaining() << " number(s) left.\n";
        int guess{ };
        std::cin >> guess;
        int closest{ searchValues(guess) };
        if (closest != guess)
        {
            std::cout << guess << " is wrong. " << closest << " was closest.\n";
            return false;
        }
        m_values.erase( std::find(m_values.begin(), m_values.end(), guess) );
    }

    std::cout << "Nice! You found all the numbers.\n";
    return true;
}

int Game::searchValues(int guess)
{
    auto found{ std::find(m_values.begin(), m_values.end(), guess) };

    if (found == m_values.end())
        return *std::min_element(m_values.begin(), m_values.end(),
                [guess](const auto x, const auto y) { 
                    return std::abs(x - guess) < std::abs(y - guess);
            }
        );
    else
        return guess;
}