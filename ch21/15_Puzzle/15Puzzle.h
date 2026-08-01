#ifndef 15PUZZLE_H
#define 15PUZZLE_H

#include "BoardSet.h"
#include "Helpers.h"
#include <cstddef>


class 15Puzzle
{
public:
    15Puzzle() = default;

    void welcome();
    void play();
    void printResults();

private:
    using Idx = std::size_t;

    enum Input
    {
        up    = 'w',
        down  = 's',
        left  = 'a',
        right = 'd',
        quit  = 'q'
    };
    std::string_view inputsStr{ "wsadq" };

    constexpr static int s_rows{ 4 };
    constexpr static int s_cols{ 4 };
    constexpr static int s_blankSpaces{ 1 };

    void reset();
    char getUserSelection();

    BoardSet<s_rows, s_cols, s_blankSpaces>  m_boardSet{ };
    Idx m_emptySpaceIdx{ };
    int m_moves{ };
    Helpers::Timer m_timer{ };
};

#endif
