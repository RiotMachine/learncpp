#include "TileBoard.h"
#include <iostream>
// #include "15Puzzle.h"

int main()
{
    TileBoard<4, 4, 15> tb{ };
    std::cout << tb;

/*
    15Puzzle puzzle{ };
    puzzle.welcome();
    puzzle.play();
    puzzle.printResults();
*/
    return 0;
}
