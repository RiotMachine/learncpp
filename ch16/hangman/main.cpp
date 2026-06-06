#include "Hangman.h"
#include <limits>

void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main()
{
    Hangman hangman{ };
    hangman.play();

    return 0;
}
