#include "15_Puzzle.h"
#include <iostream>


void 15Puzzle::welcome()
{
    std::cout << "Welcome to 15 Puzzle.\n";
}

void 15Puzzle::reset()
{
    m_boardSet.shuffleTiles();
    m_boardSet.setBoard();
    m_emptySpaceIdx = s_rows * s_cols - 1;
    m_moves = 0;
    m_timer.reset();
}

void 15Puzzle::play()
{
    reset();
    char c{ };
    while ((c = getUserSelection()) != quit)
    {
        if (c == up)

        else if (c == down)


        else if (c == left)


        else if (c == right)
    }

void 15Puzzle::printResults()
{

}

char 15Puzzle::getUserSelection()
{
    char c{ Helpers::getLowerChar() };
    while ( inputsStr.find(c) == std::string_view::npos )
 
