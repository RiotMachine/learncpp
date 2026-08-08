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

bool FifteenPuzzle::play()
{
    int shuffles{ -1 };
    while (shuffles < 0)
        shuffles = IOHelper::getInt("Enter the number of random shuffles: ");
    setupGame(shuffles);

    while (true)
    {
        std::cout << m_boardSet << '\n';
        if (isOrdered())
            return true;

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
            return false;
        case reset:
            resetGame();
            continue;
        case left:
        case right:
        case up:
        case down:
            if (moveTile(command))
                ++m_totalMoves;
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
    assert(m_boardSet.find(BoardSet::s_emptySpace).row < s_rows);
    assert(m_boardSet.find(BoardSet::s_emptySpace).col < s_cols);
    return m_boardSet.find(BoardSet::s_emptySpace);
}

bool FifteenPuzzle::moveTile(CharCommand::Command direction)
{
    {
        using namespace CharCommand;
        if (
            (direction == left && m_emptyLoc.col >= s_cols - 1)
            || (direction == right && m_emptyLoc.col <= 0)
            || (direction == up    && m_emptyLoc.row >= s_rows - 1)
            || (direction == down  && m_emptyLoc.row <= 0)
        )
        return false;
    }

    switch (direction)
    {
    case CharCommand::left:
        m_boardSet.swap(
            m_emptyLoc, Idx::D2 { m_emptyLoc.row, m_emptyLoc.col+1 }
        );
        ++m_emptyLoc.col;
        return true;
    case CharCommand::right:
        m_boardSet.swap(
            m_emptyLoc, Idx::D2 { m_emptyLoc.row, m_emptyLoc.col-1 }
        );
        --m_emptyLoc.col;
        return true;
    case CharCommand::up:
        m_boardSet.swap(
            m_emptyLoc, Idx::D2 { m_emptyLoc.row+1, m_emptyLoc.col }
        );
        ++m_emptyLoc.row;
        return true;
    case CharCommand::down:
        m_boardSet.swap(
            m_emptyLoc, Idx::D2 { m_emptyLoc.row-1, m_emptyLoc.col }
        );
        --m_emptyLoc.row;
        return true;
    default:
        assert(false && "Invalid command");
        return false;
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
    while (shuffles)
    {
        auto randomIdx{ Random::get<Idx::D1>(0, CharCommand::moves.size()-1) };
        if (moveTile(CharCommand::moves[randomIdx]))
            --shuffles;
    }
    m_boardSet.save();
    resetTracking();
}