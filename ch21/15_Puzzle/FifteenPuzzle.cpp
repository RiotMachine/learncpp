#include "CharMove.h"
#include "FifteenPuzzle.h"
#include "Helpers.h"
#include "Indices.h"
#include <cassert>
#include <iostream>

// public methods

void FifteenPuzzle::welcome() const
{
    std::cout << "Welcome to 15 Puzzle.\nOptions:\n";
    for (const auto& option : CharMove::options)
        std::cout << '\t' << option << '\n';
}

void FifteenPuzzle::play()
{
    resetGame();
    while (!checkBoard())
    {
        std::cout << m_boardSet << '\n';
        char selection;
        do
        {
            selection = Helpers::getChar();
        } while (!CharMove::isOption(selection));

        switch (selection)
        {
            using namespace CharMove;
        case quit:
            break;
        case reset:
            resetBoard();
            continue;
        case left:
        case right:
        case up:
        case down:
            moveTile(selection);
        }
    }
}

void FifteenPuzzle::printResults() const
{
    std::cout << "You performed " << m_totalMoves << " moves in " 
              << m_timer.elapsed() << " seconds."
}


// private methods

bool FifteenPuzzle::checkBoard() const
{
    const auto& b{ m_boardSet.board() };
    // s_tiles-1 == maxIdx; s_tiles-2 would test all elements,
    /// but the last tile will be s_emptySpace 
    for (Idx i{ }; i < s_tiles-3; ++i)
    {
        Idx2D currIdx{ make2D(i), s_cols };
        Idx2D nextIdx{ make2D(i+1), s_cols };
        if (b[currIdx.row][currIdx.col] + 1 != b[nextIdx.row][nextIdx.col])
            return false;
    }
    return true;
}

Indices::Idx2D FifteenPuzzle::findEmptySpace() const
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

void FifteenPuzzle::moveTile(CharMove::Option move)
{
    switch (move)
    {
    case left:
        if (m_emptyLoc.col < s_cols - 1)
            m_boardSet.swap(
                m_emptyLoc, Idx2D { m_emptyLoc.row, m_emptyLoc.col+1 }
            );
        return;
    case right:
        if (m_emptyLoc.col > 0)
            m_boardSet.swap(
                m_emptyLoc, Idx2D { m_emptyLoc.row, m_emptyLoc.col-1 }
            );
        return;
    case up:
        if (m_emptyLoc.row < s_rows - 1)
            m_boardSet.swap(
                m_emptyLoc, Idx2D { m_emptyLoc.row+1, m_emptyLoc.col }
            );
        return;
    case down:
        if (m_emptyLoc.row > 0)
            m_boardSet.swap(
                m_emptyLoc, Idx2D { m_emptyLoc.row-1, m_emptyLoc.col }
            );
        return;
    }
}

void FifteenPuzzle::resetBoard()
{
    m_boardSet.shuffleTiles();
    m_emptySpaceIdx = findEmptySpace();
}

void FifteenPuzzle::resetGame()
{
    resetBoard();
    m_totalMoves = 0;
    m_timer.reset();
}