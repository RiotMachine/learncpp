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

    using RegSeasonResult = Sport::WltResult;
    using PlayoffResult = Sport::WlResult;

    struct RegSeasonGame : Sport::Game<Team, RegSeasonResult> {};
    struct PlayoffGame   : Sport::Game<Team, PlayoffResult> {};

    struct Season : Sport::Season<Team, RegSeasonGame, PlayoffGame> {};

    class Franchise
    {
        // class member variables should be private by default
        // best practice to prefix these with 'm_'
        Team m_name{ };
        std::vector<Season> m_seasons{ };
        int m_superBowlWins{ };
    };
}

#endif
