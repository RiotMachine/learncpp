#include "FifteenPuzzle.h"
#include <iostream>

int main()
{
    FifteenPuzzle puzzle{ };
    puzzle.welcome();
    std::cout << '\n';
    if (puzzle.play())
    {
        std::cout << "You win!\n";
        puzzle.printResults();
        std::cout << '\n';
    }
    return 0;
}
