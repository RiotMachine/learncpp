#include <array>
#include <cassert>
#include <iostream>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

namespace q1
{
    std::vector v1{ 0, 2, 4, 6, 8, 10 };
    const std::vector v2{ 1.2, 3.4, 5.6, 7.8 };
    const std::vector<std::string_view> v3{ "Alex", "Brad", "Charles", "Dave" };
    std::vector v4{ 12 };
    std::vector<int> v5(12);
}

namespace q2
{
    enum Item
    {
        potion,
        torch,
        arrow,
        itemType_count
    };

    constexpr std::array<std::string_view, itemType_count> itemSingStrs{
        "health potion", "torch", "arrow"
        };

    constexpr std::array<std::string_view, itemType_count> itemPluralStrs{
        "health potions", "torches", "arrows"
        };

    template <typename Count>
    int getTotal(const std::vector<Count>& items)
    {
        int total{ };
        for (Count x: items)
            total += x;
        return total;
    }

    template <typename Count>
    void print(const std::vector<Count>& items)
    {
        std::size_t idx{ };
        for (Count x: items)
        {
            std::cout << "You have " << x << ' ' <<
                (x > 1 ? itemPluralStrs[idx] : itemSingStrs[idx]) << '\n';
            ++idx;
        }
        std::cout << "You have " << getTotal(items) << " total items\n";
    }
}

namespace q3
{
    template <typename T>
    std::optional<std::pair<T, T>> getExtremeIDX(const std::vector<T>& v)
    {
        if (v.empty())
            return { };
        std::size_t minIDX{ 0 };
        std::size_t maxIDX{ 0 };
        std::size_t currIDX{ };
        for (T x : v)
        {
            if (x < v[minIDX])
                minIDX = currIDX;
            if (x > v[maxIDX])
                maxIDX = currIDX;
            ++currIDX;
        }
        return std::pair { minIDX, maxIDX };
    }

    template <typename T>
    void print(const std::pair<T, T>& extremeIDX, const std::vector<T>& v)
    {
        std::cout << "With array (";
        std::size_t idx{ };
        for (const auto& x : v)
        {
            std::cout << ' ' << x << (idx < v.size()-1 ? "," : " ):\n");
            idx++;
        }
        std::cout << "The min element has index " << extremeIDX.first
            << " and value " << v[extremeIDX.first] << '\n';
        std::cout << "The max element has index " << extremeIDX.second
            << " and value " << v[extremeIDX.second] << '\n';
    }
}


int main()
{
    const std::vector playerItems{ 1, 5, 10 };
    assert(q2::itemType_count == playerItems.size());
    q2::print(playerItems);
    std::cout << '\n';

    std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
    std::pair p1{ *q3::getExtremeIDX(v1) };
    q3::print(p1, v1);
    std::cout << '\n';

    std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    std::pair p2{ *q3::getExtremeIDX(v2) };
    q3::print(p2, v2);

    return 0;
}
