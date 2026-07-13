// Game to calculate set of multiples of squared numbers

#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <limits>
#include <vector>

class Game
{
public:
    using ValuesArr = std::vector<int>;

    static Game setup();
    bool play();

    // returns guess if found, closest int in absolute terms otherwise
    int searchValues (int guess) const;

    int remaining() const { return static_cast<int>(m_values.size()); }

private:
    constexpr static int S_MULT_MIN{ 2 };
    constexpr static int S_MULT_MAX{ 4 };

    static ValuesArr getValues(int start, int length, int multiplier);

    Game(int x, int y, int z)
        : m_start{ x }, m_length{ y }, m_multiplier{ z },
          m_values{ getValues(x, y, z) }
    {
        assert(m_multiplier >= S_MULT_MIN && m_multiplier <= S_MULT_MAX);
        assert(m_values.size() <= std::numeric_limits<int>::max());
    }

    int m_start{ };
    int m_length{ };
    int m_multiplier{ };
    ValuesArr m_values{ };
};

#endif