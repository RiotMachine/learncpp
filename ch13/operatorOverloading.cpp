#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <iostream>
#include <iterator>  // for std::back_inserter
#include <limits>
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
    enum Team
    {
        colts,
        cowboys,
        eagles,
        texans,
    };

    std::ostream& operator<<(std::ostream& out, Team team)
    {
        switch (team)
        {
        case colts:    return out << "Colts";
        case cowboys:  return out << "Cowboys";
        case eagles:   return out << "Eagles";
        case texans:   return out << "Texans";
        default:       return out << "???";
        }
    }

    std::istream& operator>>(std::istream& in, Team& team)
    {
        std::string s{ };
        in >> s;
        s = lowerString(s);

        if (s == "colts")         team = colts;
        else if (s == "cowboys")  team = cowboys;
        else if (s == "eagles")   team = eagles;
        else if (s == "texans")   team = texans;
        else                      in.setstate(std::ios_base::failbit);

        return in;
    }

    void printResult(Team opponent, Result result)
    {
        std::cout << "Verses the " << opponent << '\t';
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
    using Season = std::map<NFL::Team, Result>;

    Season chiefs;
    chiefs.insert({ NFL::texans, loss });
    chiefs.insert({ NFL::eagles, loss });
    chiefs.insert({ NFL::colts, win });

    std::cout << "Chiefs season:\n\n";
    for (auto const& [key, val] : chiefs)
        NFL::printResult(key, val);

    std::cout << "\nInput a team: ";
    NFL::Team opponent{ };
    if (std::cin >> opponent)
    {
        if (chiefs.find(opponent) == chiefs.end())
            std::cout << "The Chiefs did not play the " << opponent << '\n';
        else
            NFL::printResult(opponent, chiefs[opponent]);
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That is not an NFL team.\n";
    }

    return 0;
}
