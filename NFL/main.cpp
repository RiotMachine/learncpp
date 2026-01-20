#include "games.h"
#include "helpers.h"
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

namespace NFL
{
    // TEAMS
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


    // GAMES
    struct RegSeasonGame
    {
        Team opponent{ };
        WltResult result{ };
        int score{ };
        int opponentScore{ };
    };

    std::ostream& operator<<(std::ostream& out, const RegSeasonGame& game)
    {
        out << game.opponent << ": " << game.result << " " << game.score
            << "-" << game.opponentScore;
        return out;
    }


    // SEASONS
    using Season = std::vector<RegSeasonGame>;

    void printSeason(Season season)
    {
        for (RegSeasonGame game : season)
            std::cout << '\t' << game << '\n';
    }

    void searchSeason(Season season)
    {
        std::cout << "\nInput a team: ";
        Team opponent{ };
        if (std::cin >> opponent)
        {
            bool flag{ true };
            for (RegSeasonGame game : season)
                if (game.opponent == opponent)
                {
                    flag = false;
                    std::cout << game << '\n';
                }
            if (flag)
                std::cout << "Your team did not play the " << opponent << '\n';
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That is not an NFL team.\n";
        }
    }
}

int main()
{
    NFL::Season chiefs{
        NFL::RegSeasonGame{ NFL::texans, WltResult::loss, 10, 20 },
        NFL::RegSeasonGame{ NFL::eagles, WltResult::loss, 17, 20 },
        NFL::RegSeasonGame{ NFL::colts, WltResult::win, 23, 20 },
        NFL::RegSeasonGame{ NFL::broncos, WltResult::loss, 13, 20 },
        NFL::RegSeasonGame{ NFL::broncos, WltResult::loss, 19, 22 }
    };

    std::cout << "Chiefs season:\n";
    NFL::printSeason(chiefs);

    NFL::searchSeason(chiefs);

    return 0;
}
