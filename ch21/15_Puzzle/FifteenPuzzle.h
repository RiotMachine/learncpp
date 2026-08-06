#ifndef FIFTEENPUZZLE_H
#define FIFTEENPUZZLE_H

#include "Indices.h"
#include "TileBoard.h"
#include <cassert>
#include <iostream>

class FifteenPuzzle
{
public:
    FifteenPuzzle() = default;

    void play()
    {
        std::cout << m_boardSet;
    };

private:
    enum Move
    {
       left  = 'a',
       right = 'd',
       up    = 'w',
       down  = 's',
       reset = 'r',
       quit  = 'q'
    };

    constexpr static int s_rows { 4 };
    constexpr static int s_cols { 4 };
    constexpr static int s_tiles{ s_rows * s_cols - 1 };

    using BoardSet = TileBoard<s_rows, s_cols, s_tiles>;
    using Idx      = Indices::Idx;
    using Idx2D    = Indices::Idx2D;

    Idx2D findEmptySpace() const
    {
        const auto& b{ m_boardSet.board() };
        for (Idx i{ }; i < b.size(); ++i)
        {
            for (Idx j{ }; j < b[i].size(); ++j)
            {
                if (b[i][j] == BoardSet::s_emptySpace)
                    return Idx2D { i, j };
            }
        }
        assert (false && "Missing empty space");
    }       

    BoardSet m_boardSet{ };
    Idx2D m_emptySpaceIdx{ findEmptySpace() };
};

#endif