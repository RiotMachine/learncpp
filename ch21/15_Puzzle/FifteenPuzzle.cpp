#include "CharCommand.h"
#include "FifteenPuzzle.h"
#include "Idx.h"
#include "IOHelper.h"
#include "Random.h"
#include <cassert>
#include <iostream>

// Public methods

void FifteenPuzzle::welcome() const
{
    std::cout << "Welcome to 15 Puzzle.\nCommands:\n";
    for (const auto option : CharCommand::commands)
        std::cout << '\t' << option << '\n';
}

void FifteenPuzzle::play()
{
    int input{ -1 };
    while (input < 0)
        input = IOHelper::getInt("Enter the number of shuffles: ");
    setupGame(input);

    while (true)
    {
        std::cout << m_boardSet << '\n';
        if (isOrdered())
            break;

        char input{ };
        while (!CharCommand::isCommand(input))
        {
            std::cout << "Enter a command: ";
            input = IOHelper::getChar();   
        }

        CharCommand::Command command{ input };
        switch (command)
        {
            using namespace CharCommand;
        case quit:
            return;
        case reset:
            resetGame();
            continue;
        case left:
        case right:
        case up:
        case down:
            moveTile(command);
        }
    }
}

void FifteenPuzzle::printResults() const
{
    std::cout << "You performed " << m_totalMoves << " moves in " 
        << m_timer.elapsed() << " seconds.";
}


// Private methods

bool FifteenPuzzle::isOrdered() const
{
    // s_tiles would test all elements, but the last tile will be s_emptySpace
    for (Idx::D1 i{ }; i < s_tiles-1; ++i)
    {
        if (m_boardSet[i] + 1 != m_boardSet[i + 1])
            return false;
    }
    return true;
}

Idx::D2 FifteenPuzzle::findEmptySpace() const
{
    return m_boardSet.find(BoardSet::s_emptySpace);
}

void FifteenPuzzle::moveTile(CharCommand::Command direction)
{
    switch (direction)
    {
    case CharCommand::left:
        if (m_emptyLoc.col < s_cols - 1)
        {
            m_boardSet.swap(
                m_emptyLoc, Idx::D2 { m_emptyLoc.row, m_emptyLoc.col+1 }
            );
            ++m_emptyLoc.col;
            ++m_totalMoves;
        }
        return;
    case CharCommand::right:
        if (m_emptyLoc.col > 0)
        {
            m_boardSet.swap(
                m_emptyLoc, Idx::D2 { m_emptyLoc.row, m_emptyLoc.col-1 }
            );
            --m_emptyLoc.col;
            ++m_totalMoves;
        }
        return;
    case CharCommand::up:
        if (m_emptyLoc.row < s_rows - 1)
        {
            m_boardSet.swap(
                m_emptyLoc, Idx::D2 { m_emptyLoc.row+1, m_emptyLoc.col }
            );
            ++m_emptyLoc.row;
            ++m_totalMoves;
        }
        return;
    case CharCommand::down:
        if (m_emptyLoc.row > 0)
        {
            m_boardSet.swap(
                m_emptyLoc, Idx::D2 { m_emptyLoc.row-1, m_emptyLoc.col }
            );
            --m_emptyLoc.row;
            ++m_totalMoves;
        }
        return;
    }
}

void FifteenPuzzle::resetTracking()
{
    m_emptyLoc = findEmptySpace();
    m_totalMoves = 0;
    m_timer.reset();
}

void FifteenPuzzle::resetGame()
{
    m_boardSet.reset();
    resetTracking();
}

void FifteenPuzzle::setupGame(int shuffles)
{
    assert(shuffles >= 0);
    while (shuffles--)
    {
        auto randomIdx{ Random::get<Idx::D1>(0, CharCommand::moves.size()-1) };
        moveTile(CharCommand::moves[randomIdx]);
    }
    m_boardSet.save();
    resetTracking();
}