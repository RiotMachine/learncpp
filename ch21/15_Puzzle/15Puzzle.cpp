#include "15_Puzzle.h"
#include <iostream>


void 15Puzzle::welcome()
{
    std::cout << "Welcome to 15 Puzzle.\n";
}


void 15Puzzle::play()
{
    m_boardSet.shuffleTiles();
    m_boardSet.setBoard();
    m_emptySpaceIdx = s_rows * s_cols - 1;
    char c{ };
    while (!validateInput(c))
        c = Helpers::getLowerChar();
    while (c != Input::quit))
}

void 15Puzzle::printResults()
{

}
