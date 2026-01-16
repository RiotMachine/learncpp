#include <iostream>
#include <map>
#include <string_view>

enum Opponent
{
    colts,
    cowboys,
    eagles,
    texans,
};

enum Result
{
    win,
    loss,
    tie,
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
    std::cout << "Verses the " << printOpp(opp) << '\t';
    if (result == win)
        std::cout << "Chiefs won!\n";
    else if (result == loss)
        std::cout << "Chiefs lost :(\n";
    else
        std::cout << "It was a tie, bro\n";
}

int main()
{
    std::map<Opponent, Result> season;

    season.insert({ texans, loss });
    season.insert({ eagles, loss });
    season.insert({ colts, win });

    for (auto const& [key, val] : season)
        printResult(key, val);

    return 0;
}
