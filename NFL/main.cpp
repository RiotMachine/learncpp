#include "nfl.h"
#include <iostream>

int main()
{
    NFL::Season chiefs2025{
        NFL::chiefs, {
        NFL::RegSeasonGame{ NFL::texans,  NFL::RegSeasonResult::loss, 10, 20 },
        NFL::RegSeasonGame{ NFL::eagles,  NFL::RegSeasonResult::loss, 17, 20 },
        NFL::RegSeasonGame{ NFL::colts,   NFL::RegSeasonResult::win,  23, 20 },
        NFL::RegSeasonGame{ NFL::broncos, NFL::RegSeasonResult::loss, 13, 20 },
        NFL::RegSeasonGame{ NFL::broncos, NFL::RegSeasonResult::loss, 19, 22 }
        }
    };

    std::cout << "2025 Chiefs:\n\n";
    chiefs2025.print();
    std::cout << '\n';
    chiefs2025.search();

    return 0;
}
