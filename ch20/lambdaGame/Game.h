#ifndef GAME_H
#define GAME_H

#include "Random.h"
#include <vector>

class Game
{
public:
    static Game setup();
    bool play();
    int searchValues(int guess);

    int remaining()  { return m_values.size(); }

private:
    constexpr static int S_MULT_MIN{ 2 };
    constexpr static int S_MULT_MAX{ 4 };

    Game(int x, int y)
        : m_start{ x }, m_length{ y },
          m_multiplier{ Random::get(S_MULT_MIN, S_MULT_MAX) }
    {
        m_values.reserve(m_length);
        for (int i{ }; i < m_length; ++i)
            m_values.push_back(
                (m_start + i) * (m_start + i) * m_multiplier
            );
    }

    int m_start{ };
    int m_length{ };
    int m_multiplier{ };
    std::vector<int> m_values{ };
};

#endif