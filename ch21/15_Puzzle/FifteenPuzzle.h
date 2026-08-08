#ifndef FIFTEENPUZZLE_H
#define FIFTEENPUZZLE_H

#include "CharCommand.h"
#include "Idx.h"
#include "TileBoard.h"
#include "Timer.h"

class FifteenPuzzle
{
public:
    FifteenPuzzle() = default;

    void welcome() const;
    void play();
    void printResults() const;

private:
    constexpr static int s_rows { 4 };
    constexpr static int s_cols { 4 };
    constexpr static int s_tiles{ s_rows * s_cols - 1 };

    using BoardSet = TileBoard<s_rows, s_cols, s_tiles>;

    bool isOrdered() const;
    Idx::D2 findEmptySpace() const;
    void moveTile(CharCommand::Command command);
    void resetTracking();
    void resetGame();
    void setupGame(int shuffles);

    BoardSet m_boardSet{ };
    Idx::D2 m_emptyLoc{ findEmptySpace() };
    int m_totalMoves{ };
    Timer m_timer{ };
};

#endif