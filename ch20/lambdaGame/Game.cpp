#include "Game.h"
#include "Random.h"
#include <algorithm>
#include <cstdlib>   // for std::abs()
#include <iostream>
#include <vector>

int getInt(std::string_view str = {})
{
    std::cout << str;
    int x;
    std::cin >> x;
    return x;
}


Game Game::setup()
{
    return Game {
        getInt("Start where? "), 
        getInt("How many numbers? "),
        Random::get(S_MULT_MIN, S_MULT_MAX)
    };
}

Game::ValuesArr Game::getValues(int start, int length, int multiplier)
{
    ValuesArr arr;
    arr.reserve(length);
    for (int i{ }; i < length; ++i)
        arr.push_back(
            (start + i) * (start + i) * multiplier
        );
    return arr;
}       


bool Game::play()
{
    std::cout << "I generated " << m_length << " numbers.\n"
        << "Do you know each square multiplied by " << m_multiplier << "?\n";

    while (remaining())
    {
        std::cout << remaining() << " number(s) left.\n";
        int guess{ getInt() };
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


int Game::searchValues(int guess) const
{
    auto found{ std::find(m_values.begin(), m_values.end(), guess) };

    if (found == m_values.end())
        found = std::min_element(m_values.begin(), m_values.end(),
                [guess](const auto x, const auto y) { 
                    return std::abs(x - guess) < std::abs(y - guess);
                }
            );

    return *found;
}