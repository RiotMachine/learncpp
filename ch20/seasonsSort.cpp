#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{ };
    double averageTemp{ };
};


int main()
{
    std::array<Season, 4> seasons{{
        { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall",   288.0 },
        { "Winter", 263.0 }
    }};

    std::sort(seasons.begin(), seasons.end(),
        [](const Season& s1, const Season& s2) {
            return s1.averageTemp < s2.averageTemp;
        }
    );

    for (const auto& season : seasons)
        std::cout << season.name << '\n';

    return 0;
}