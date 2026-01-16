#include <iostream>
#include <map>
#include <string_view>

// enumerators of unscoped enumerations occupy same scope as enumeration

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

    constexpr std::string_view printOpp(Opponent opp)
    {
        switch (opp)
        {
        case colts:    return "Colts";
        case cowboys:  return "Cowboys";
        case eagles:   return "Eagles";
        case texans:   return "Texans";
        default:       return "???";
        }
    }

    void printResult(Opponent opp, Result result)
    {
        std::cout << "\tVerses the " << printOpp(opp) << '\t';
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

    std::cout << "Chiefs season:\n";
    for (auto const& [key, val] : chiefs)
        NFL::printResult(key, val);

    return 0;
}
