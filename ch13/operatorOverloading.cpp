#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <iostream>
#include <iterator>  // for std::back_inserter
#include <map>
#include <optional>
#include <string>
#include <string_view>

std::string lowerString(std::string_view sv)
{
    std::string lower{};
    std::transform(sv.begin(), sv.end(), std::back_inserter(lower),
    [](char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    });
    return lower;
}

enum Result
{
    win,
    loss,
    tie,
};

namespace NFL
{
    enum Opponent
    {
        colts,
        cowboys,
        eagles,
        texans,
    };

    std::ostream& operator<<(std::ostream& out, Opponent opp)
    {
        switch (opp)
        {
        case colts:    return out << "Colts";
        case cowboys:  return out << "Cowboys";
        case eagles:   return out << "Eagles";
        case texans:   return out << "Texans";
        default:       return out << "???";
        }
    }

    constexpr std::optional<Opponent> getOppFromString(std::string_view sv)
    {
        if (sv == "colts")    return colts;
        if (sv == "cowboys")  return cowboys;
        if (sv == "eagles")   return eagles;
        if (sv == "texans")   return texans;

        return {};
    }

    void printResult(Opponent opp, Result result)
    {
        std::cout << "Verses the " << opp << '\t';
        if (result == win)
            std::cout << "win!\n";
        else if (result == loss)
            std::cout << "loss :(\n";
        else
            std::cout << "tie, bro\n";
    }
}

int main()
{
    using Season = std::map<NFL::Opponent, Result>;

    Season chiefs;
    chiefs.insert({ NFL::texans, loss });
    chiefs.insert({ NFL::eagles, loss });
    chiefs.insert({ NFL::colts, win });

    std::cout << "Chiefs season:\n\n";
    for (auto const& [key, val] : chiefs)
        NFL::printResult(key, val);

    std::cout << "\nInput a team: ";
    std::string input{};
    std::cin >> input;
    std::optional<NFL::Opponent> opponent{ NFL::getOppFromString(lowerString(input)) };
    if (!opponent)
        std::cout << input << " is not an NFL team.\n";
    else
        if (chiefs.find(*opponent) == chiefs.end())
            std::cout << "The Chiefs did not play the " << input << '\n';
        else
            NFL::printResult(*opponent, chiefs[*opponent]);

    return 0;
}
