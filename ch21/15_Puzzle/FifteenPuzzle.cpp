#include "FifteenPuzzle.h"
#include "Indices.h"
#include <cassert>
#include <iostream>

// public methods

void FifteenPuzzle::welcome()
{
    std::cout << "Welcome to 15 Puzzle.\n"
}

void FifteenPuzzle::play()
{
    while (true)
    {
        char selection;
        do
        {
            selection = Helpers::getChar();
        } while (moveStr.find(selection) == std::string_view::npos);

        switch (selection)
        {
            using namespace CharMove;
        case quit:
            break;
        case reset:
            reset();
            continue;
        case left:

        case right:

        case up:

        case down:

        }
    }
}

void FifteenPuzzle::printResults()
{

}



// private methods

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