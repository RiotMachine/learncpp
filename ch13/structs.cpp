#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <iostream>
#include <iterator>  // for std::back_inserter
#include <limits>
#include <string>
#include <string_view>
#include <vector>

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

enum class WltResult
{
    win,
    loss,
    tie,
};

enum class WlResult
{
    win,
    loss,
};

namespace NFL
{
    enum Team
    {
        broncos,
        colts,
        cowboys,
        eagles,
        texans,
    };

    std::ostream& operator<<(std::ostream& out, Team team)
    {
        switch (team)
        {
        case broncos:  return out << "Broncos";
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

        if (s == "broncos")       team = broncos;
        else if (s == "colts")    team = colts;
        else if (s == "cowboys")  team = cowboys;
        else if (s == "eagles")   team = eagles;
        else if (s == "texans")   team = texans;
        else                      in.setstate(std::ios_base::failbit);

        return in;
    }

    struct RegSeasonGame
    {
        Team opponent{ };
        WltResult result{ };
        int score{ };
        int opponentScore{ };
    };

    void printResult(RegSeasonGame game)
    {
        std::cout << "Verses the " << game.opponent << '\t';
        if (game.result == WltResult::win)
            std::cout << "win!\n";
        else if (game.result == WltResult::loss)
            std::cout << "loss :(\n";
        else
            std::cout << "tie, bro\n";
    }

    void printResult(Team opponent, WlResult result)
    {
        std::cout << "Verses the " << opponent << '\t';
        if (result == WlResult::win)
            std::cout << "win. Advanced to the next round.\n";
        else
            std::cout << "loss. Knocked out of the playoffs.\n";
    }
}

int main()
{
    using Season = std::vector<NFL::RegSeasonGame>;

    Season chiefs{
        NFL::RegSeasonGame{ NFL::texans, WltResult::loss, 10, 20 },
        NFL::RegSeasonGame{ NFL::eagles, WltResult::loss, 17, 20 },
        NFL::RegSeasonGame{ NFL::colts, WltResult::win, 23, 20 },
        NFL::RegSeasonGame{ NFL::broncos, WltResult::loss, 13, 20 },
        NFL::RegSeasonGame{ NFL::broncos, WltResult::loss, 19, 22 }
    };

    std::cout << "Chiefs season:\n\n";
    for (NFL::RegSeasonGame game : chiefs)
        NFL::printResult(game);

    std::cout << "\nInput a team: ";
    NFL::Team opponent{ };
    if (std::cin >> opponent)
    {
        bool flag{ true };
        for (NFL::RegSeasonGame game : chiefs)
            if (game.opponent == opponent)
            {
                flag = false;
                NFL::printResult(game);
            }
        if (flag)
            std::cout << "The Chiefs did not play the " << opponent << '\n';
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That is not an NFL team.\n";
    }

    return 0;
}
