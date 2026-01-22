#include <iostream>
#include <string_view>

namespace Procedural
{
    enum AnimalType
    {
        cat,
        dog,
        chicken,
        snake,
    };

    constexpr std::string_view animalName(AnimalType type)
    {
        switch (type)
        {
        case cat:     return "cat";
        case dog:     return "dog";
        case chicken: return "chicken";
        case snake:   return "snake";
        default:      return "";
        }
    }

    constexpr int numLegs(AnimalType type)
    {
        switch (type)
        {
        case cat:
        case dog:     return 4;
        case chicken: return 2;
        case snake:
        default:      return 0;
        }
    }
}

namespace ObjectOriented
{
    struct Cat
    {
        std::string_view name{ "cat" };
        int numLegs{ 4 };
    };

    struct Dog
    {
        std::string_view name{ "dog" };
        int numLegs{ 4 };
    };

    struct Chicken
    {
        std::string_view name{ "chicken" };
        int numLegs{ 2 };
    };

    struct Snake
    {
        std::string_view name{ "snake" };
        int numLegs{ 0 };
    };
}

int main()
{
    constexpr Procedural::AnimalType animal{ Procedural::snake };
    std::cout << "A " << Procedural::animalName(animal) << " has " <<
        Procedural::numLegs(animal) << " legs\n";

    constexpr ObjectOriented::Snake animal2;
    std::cout << "A " << animal2.name << " has " << animal2.numLegs <<
        " legs\n";

    return 0;
}
