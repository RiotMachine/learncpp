#include <array>
#include <string>
#include <string_view>

class Hangman
{
public:
    static constexpr int s_defaultTries{ 6 };

    Hangman(int x)
        : m_tries{ x } {}
    Hangman(std::string_view sv, int x = s_defaultTries)
        : m_word{ sv }, m_tries{ x } {}
    Hangman() = default;

    void play();

private:
    // Setup Functions
    std::string_view generateWord();
    void setupTryWords();

    // Play Functions
    void printState();
    char getLetter();
    bool updateTryWords(char c);
    void updateHasWon();

    // tryRight displays correct and missing letters
    // tryWrong displays wrong guesses and tries remaining
    const std::string m_word { generateWord() };
    int m_tries              { s_defaultTries };
    std::string m_tryRight   { };
    std::string m_tryWrong   { };
    bool m_hasWon            { false };

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
