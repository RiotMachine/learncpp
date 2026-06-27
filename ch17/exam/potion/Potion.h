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
        invisibility
        max_types
    };

    struct Data
    {
        std::string_view name{ };
        int cost{ };
    };

    constexpr std::array types{
        healing, mana, speed, invisibility
    };

    constexpr std::array data{
        Data {"healing",      20},
        Data {"mana",         30},
        Data {"speed",        12},
        Data {"invisibility", 50}
    };

    static_assert(max_types == types.size());
    static_assert(max_types == data.size());

    void list()
    {
        for (const auto& e : types)
        {
            const Data& potion{ data[e] };
            std::cout << static_cast<int>(e) << ") " << potion.name
                << " costs " << potion.cost << '\n';
        }
    }
}

#endif
