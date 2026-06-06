#include "Hangman.h"
#include "helpers.h"
#include "random.h"
#include <cctype>   // for std::isalpha
#include <iostream>


// Setup Functions

// generate a random number to index into wordBank
std::string_view Hangman::generateWord()
{
    return s_wordBank[ Random::get(0, s_wordBank.size()-1) ];
}

void Hangman::setupTryWords()
{
    m_tryRight.resize( m_word.size() );
    for (char& c : m_tryRight)
        c = '_';

    m_tryWrong.resize(m_tries);
    for (char& c : m_tryWrong)
        c = '+';
}


// Play Functions

void Hangman::play()
{
    std::cout << "Welcome to C++man (a Hangman variant)\n"
        << "To win, guess the word. To lose, run out of pluses.\n\n";
    setupTryWords();

    while (m_tries > 0 && !m_hasWon)
    {
        printState();
        char c{ Helper::lowercase( getLetter() ) };
        if (updateTryWords(c))
            std::cout << "\n'" << c << "' is in the word.\n";
        else
            std::cout << "\n'" << c << "' is not in the word.\n";
    }

    printState();
    if (m_hasWon)
        std::cout << "\nYou win! ";
    else
        std::cout << "\nYou lost! ";
    std::cout << "The word was \"" << m_word << "\"\n";
}

void Hangman::printState()
{
    std::cout << "The word: " << m_tryRight << '\t'
        << "Wrong guesses: " << m_tryWrong << '\n';
}

// prompt for user input until input begins with letter
char Hangman::getLetter()
{
    char c{ };
    while (true)
    {
        std::cout << "Enter your next letter: ";
        std::cin >> c;
        Helper::clearBuffer();
        if (std::isalpha(c))
            break;
        std::cout << "That wasn't a valid input. Try again.\n";
    }
    return c;
}

bool Hangman::updateTryWords(char c)
{
    bool inWordFlag{ false };

    // reveal letter in m_tryRight if letter is in m_word
    for (Helper::IDX i{ }; i < m_word.size(); ++i)
    {
        if (m_word[i] == c)
        {
            inWordFlag = true;
            m_tryRight[i] = c;
        }
    }
    // if not, decrease user's tries and log wrong letter in m_tryWrong
    if (!inWordFlag)
    {
        m_tryWrong[m_tries-1] = c;
        --m_tries;
    }
    // user can win only after a correct guess
    else
        updateHasWon();

    return inWordFlag;
}

// user wins when all letters in word have been revealed
void Hangman::updateHasWon()
{
    for (const char c : m_tryRight)
        if (!std::isalpha(c))
            return;
    m_hasWon = true;
}
