#ifndef FIFTEENPUZZLE_H
#define FIFTEENPUZZLE_H

#include "Indices.h"
#include "Helpers.h"
#include "TileBoard.h"

class FifteenPuzzle
{
public:
    FifteenPuzzle() = default;

    void welcome();
    void play();
    void printResults();

private:
    using Idx   = Indices::Idx;
    using Idx2D = Indices::Idx2D;

    constexpr static int s_rows { 4 };
    constexpr static int s_cols { 4 };
    constexpr static int s_tiles{ s_rows * s_cols - 1 };

    using BoardSet = TileBoard<s_rows, s_cols, s_tiles>;

    Idx2D findEmptySpace() const;
    void reset();

    BoardSet m_boardSet{ };
    Idx2D m_emptySpaceIdx{ findEmptySpace() };
    int m_totalMoves{ };
    Helpers::Timer m_timer{ };
};

#endif