#include "nfl.h"
#include "sport.h"
#include <iostream>

int main()
{
    NFL::Season chiefs2025{ NFL::chiefs };
    chiefs2025.regSeasonGames = {
        NFL::RegSeasonGame{ NFL::texans,  Sport::WltResult::loss, 10, 20 },
        NFL::RegSeasonGame{ NFL::eagles,  Sport::WltResult::loss, 17, 20 },
        NFL::RegSeasonGame{ NFL::colts,   Sport::WltResult::win,  23, 20 },
        NFL::RegSeasonGame{ NFL::broncos, Sport::WltResult::loss, 13, 20 },
        NFL::RegSeasonGame{ NFL::broncos, Sport::WltResult::loss, 19, 22 }
    };

    std::cout << "Chiefs season:\n\n";
    chiefs2025.print();
    chiefs2025.search();

    return 0;
}
