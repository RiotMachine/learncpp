#include "FifteenPuzzle.h"
#include <iostream>

int main()
{
    FifteenPuzzle puzzle{ };
    puzzle.welcome();
    std::cout << '\n';
    puzzle.play();
    puzzle.printResults();
    std::cout << '\n';

    return 0;
}
