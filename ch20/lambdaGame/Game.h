// Game to guess members of set of multiples of squared numbers

#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <vector>

class Game
{
public:
    using ValuesArr = std::vector<int>;

    static Game setup();
    bool play();
    std::size_t remaining() const { return m_values.size(); }

private:
    constexpr static int S_MULT_MIN{ 2 };
    constexpr static int S_MULT_MAX{ 4 };

    static ValuesArr getValues(int start, int length, int multiplier);

    Game(int x, int y, int z)
        : m_initLen{ y }, m_multiplier{ z },
          m_values{ getValues(x, y, z) }
    {
        assert(m_multiplier >= S_MULT_MIN && m_multiplier <= S_MULT_MAX);
    }

    // returns iterator to guess if found, to closest num otherwise
    auto searchValues (int guess) const;

    const int m_initLen{ };
    const int m_multiplier{ };
    ValuesArr m_values{ };
};

#endif