#ifndef POTION_H
#define POTION_H

#include <array>
#include <iostream>
#include <string_view>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_types
    };

    struct Data
    {
        Type type{ };
        std::string_view name{ };
        int cost{ };
    };

    constexpr std::array potions{
        Data { healing, "healing", 20 },
        Data { mana, "mana", 30 },
        Data { speed, "speed", 12 },
        Data { invisibility, "invisibility", 50 }
    };

    static_assert(potions.size() == max_types);

    inline void printMenu()
    {
        std::cout << "Here is our selection for today:\n";
        for (Data e : potions)
            std::cout << static_cast<int>(e.type)+1 << ") " 
                << e.name << " costs " << e.cost << '\n';
    }
}

#endif