#include "Game.h"
#include "Random.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>   // for std::abs()
#include <iostream>
#include <vector>

using Idx = std::size_t;

namespace
{
    int getInt(std::string_view str = {})
    {
        std::cout << str;
        int x;
        std::cin >> x;
        return x;
    }
}

Game Game::setup()
{
    int start{ getInt("Start where? ") };
    int length{ getInt("How many numbers? ") };
    return Game {
        start,
        length,
        Random::get(S_MULT_MIN, S_MULT_MAX)
    };
}

Game::ValuesArr Game::getValues(int start, int length, int multiplier)
{
    ValuesArr arr;
    assert(length >= 0);
    arr.reserve(static_cast<Idx>(length));
    for (int i{ }; i < length; ++i)
        arr.push_back(
            (start + i) * (start + i) * multiplier
        );
    return arr;
}       

auto Game::searchValues(int guess) const
{
    return std::min_element(m_values.begin(), m_values.end(),
                [guess](const auto x, const auto y) { 
                    return std::abs(x - guess) < std::abs(y - guess);
                });
}

bool Game::play()
{
    std::cout << "I generated " << m_initLen << " numbers.\n"
        << "Do you know each square multiplied by " << m_multiplier << "?\n";

    while (remaining())
    {
        std::cout << remaining() << " number(s) left.\n";
        int guess{ getInt() };
        auto closestIt{ searchValues(guess) };
        if (*closestIt != guess)
        {
            std::cout << guess << " is wrong. " << *closestIt << " was closest.\n";
            return false;
        }
        m_values.erase(closestIt);
    }

    std::cout << "Nice! You found all the numbers.\n";
    return true;
}