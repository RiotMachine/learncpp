#include <array>
#include <string>
#include <string_view>
#include <vector>

class Hangman
{
public:
    constexpr int s_defaultTries{ 6 };

    Hangman(int x)
        : m_tries{ x } {}
    Hangman(std::string_view sv, int x = s_defaultTries)
        : m_word{ sv }, m_tries{ x } {}
    Hangman() = default;

    void play() const;

private:
    std::string_view generateWord() const;
    char getLetter();
    void printState();

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
