#include "Hangman.h"
#include "random.h"
#include <array>
#include <cctype>   // for std::isalpha, std::tolower
#include <iostream>
#include <vector>

void Hangman::play() const
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n"
        << "To win: guess the word. To lose: run out of pluses.\n\n";

    while (m_tries > 0 && !m_hasWon)
    {
        printState();
        char c{ std::tolower(getLetter()) };
        if (isChar(c))
        {
            std::cout << "Yes, '" << c << "' is in the word!\n";
            hasWon = updateTryWord(c);
        }
        else
        {
            std::cout << "No, '" << c << "' is not in the word!\n";
            --m_tries;
        }
    }

    if (hasWon)
        std::cout << "You win!";
    else
        std::cout << "You lost!";
    std::cout << "The word was: " << m_word << '\n';
}


std::string_view Hangman::generateWord() const
{
    return s_wordBank[Random::get(0, s_wordBank.size()-1)];
}


char Hangman::getLetter()
{
    while (true)
    {
        std::cout << "Enter your next letter: ";
        char c{ };
        std::cin >> c;
        if (!std::isalpha(c))
            std::cout << "That wasn't a valid input. Try again.\n";
        else
        {
            std::cout << "You entered: " << c << '\n';
            break;
        }
        clearBuffer();
    }
    return c;
}

void Hangman::printState()
{
    std::cout << "The word: " << m_tryWord << '\t'
        << "Wrong guesses: << m_tryGuess << '\n';
}
