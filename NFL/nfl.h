#ifndef NFL_H
#define NFL_H

#include "sport.h"
#include <iosfwd>
#include <vector>

namespace NFL
{
    enum Team
    {
        broncos,
        chiefs,
        colts,
        cowboys,
        eagles,
        texans,
    };

    std::ostream& operator<<(std::ostream& out, Team team);
    std::istream& operator>>(std::istream& in, Team& team);

    struct RegSeasonGame : Sport::Game<Team, Sport::WltResult> {};
    struct PlayoffGame   : Sport::Game<Team, Sport::WlResult> {};

    constexpr int regSeasonLength{ 17 };
    struct Season : Sport::Season<Team, RegSeasonGame, PlayoffGame, regSeasonLength> {};

    class Franchise
    {
        Team name{ };
        std::vector<Season> seasons{ };
        int superBowlWins{ };
    };
}

#endif
