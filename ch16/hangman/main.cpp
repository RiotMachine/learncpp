#include "random.h"
#include <array>
#include <cctype>   // for std::isalpha, std::tolower
#include <iostream>
#include <limits>
#include <vector>

void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Hangman
{
public:
    constexpr int s_defaultTries{ 6 };

    Hangman(int x)
        : m_tries{ x } {}
    Hangman(std::string_view sv, int x = s_defaultTries)
        : m_word{ sv }, m_tries{ x } {}
    Hangman() = default;

    void play() const
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

private:
    std::string_view generateWord() const
    {
        return s_wordBank[Random::get(0, s_wordBank.size()-1)];
    }

    char getLetter()
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

    void printState()
    {
        std::cout << "The word: " << m_tryWord << '\t'
            << "Wrong guesses: << m_tryGuess << '\n';
    }

    std::string m_word{ generateWord() };
    int m_tries{ s_defaultTries };
    std::string m_tryWord{ };
    std::vector<char> m_tryGuess(s_defaultTries);
    bool m_hasWon{ false };

    static constexpr std::array s_wordBank{
        "mystery",
        "broccoli",
        "account",
        "almost",
        "spaghetti",
        "opinion",
        "beautiful",
        "distance",
        "luggage"
    };
};


int main()
{
    Hangman hangman{ };
    hangman.play();

    return 0;
}
