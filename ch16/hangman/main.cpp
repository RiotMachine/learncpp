#include "Hangman.h"
#include "helpers.h"
#include <iostream>

int main()
{
    while (true)
    {
        Hangman hangman{ };
        hangman.play();
        std::cout << "Would you like to play again?\n"
            << "Enter 1 to play, anything else to exit: ";
        char c{ };
        std::cin >> c;
        if (c != '1')
            break;
        Helper::clearBuffer();
        std::cout << '\n';
    }

    std::cout << "Goodbye.\n";
    return 0;
}
