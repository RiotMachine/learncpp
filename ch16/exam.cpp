#include <array>
#include <iostream>
#include <string_view>
#include <utility>      // for std::pair
#include <vector>

using IDX = std::size_t;

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
    enum ItemType
    {
        potion,
        torch,
        arrow,
        itemType_count
    };

    using Inventory = std::array<int, itemType_count>;
    using Dictionary = std::array<std::array<std::string_view, 2>, itemType_count>;

    constexpr Dictionary itemDict{{
        { "health potion", "health potions" },
        { "torch", "torches" },
        { "arrow", "arrows" }
        }};

    int getTotal(const Inventory& inventory)
    {
        int total{ };
        for (const auto count: inventory)
            total += count;
        return total;
    }

    void print(const Inventory& inventory)
    {
        for (IDX i{ }; i < itemType_count; ++i)
            std::cout << "You have " << inventory[i] << ' '
                << (inventory[i] == 1 ? itemDict[i][0] : itemDict[i][1]) << '\n';

        std::cout << "You have " << getTotal(inventory) << " total items\n";
    }
}

namespace q4
{
    std::vector<int> makeVector()
    {
        std::cout << "Enter numbers to add (use -1 to stop): ";
        std::vector<int> v{ };
        while (true)
        {
            int x{ };
            std::cin >> x;
            if (x == -1)
                break;
            v.push_back(x);
        }
        return v;
    }

    template <typename T>
    std::pair<IDX, IDX> getExtremeIDX(const std::vector<T>& v)
    {
        IDX minIDX{ 0 };
        IDX maxIDX{ 0 };
        for (IDX i{ }; i < v.size(); ++i)
        {
            if (v[i] < v[minIDX])
                minIDX = i;
            if (v[i] > v[maxIDX])
                maxIDX = i;
        }
        return { minIDX, maxIDX };
    }

    template <typename T>
    void print(const std::vector<T>& v)
    {
        if (v.empty())
        {
            std::cout << "The array is empty.\n";
            return;
        }

        std::cout << "With array ( ";
        bool comma{ false };
        for (const auto& x : v)
        {
            if (comma)
                std::cout << ", ";
            std::cout << x;
            comma = true;
        }
        std::cout << " ):\n";

        std::pair extremeIDX{ getExtremeIDX(v) };
        std::cout << "The min element has index " << extremeIDX.first
            << " and value " << v[extremeIDX.first] << '\n';
        std::cout << "The max element has index " << extremeIDX.second
            << " and value " << v[extremeIDX.second] << '\n';
    }
}


int main()
{
    const q2::Inventory inventory{ 1, 5, 10 };
    q2::print(inventory);
    std::cout << '\n';

    const std::vector v{ q4::makeVector() };
    q4::print(v);
    std::cout << '\n';

    return 0;
}
