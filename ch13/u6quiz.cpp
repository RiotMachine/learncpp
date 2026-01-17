#include <iostream>
#include <optional>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal animal)
{
    switch(animal)
    {
    case Animal::pig:     return "pig";
    case Animal::chicken: return "chicken";
    case Animal::goat:    return "goat";
    case Animal::cat:     return "cat";
    case Animal::dog:     return "dog";
    case Animal::duck:    return "duck";
    default:              return "???";
    }
}

std::optional<int> getNumberOfLegs(Animal animal)
{
    switch(animal)
    {
    case Animal::pig:     return 4;
    case Animal::goat:    return 4;
    case Animal::cat:     return 4;
    case Animal::dog:     return 4;
    case Animal::chicken: return 2;
    case Animal::duck:    return 2;
    default:              return { };
    }
}

void printNumberOfLegs(Animal animal)
{
    std::optional<int> legs{ getNumberOfLegs(animal) };
    if (!legs)
        std::cout << "Why did you pass me an unreal animal fool?\n";
    else
        std::cout << "A " << getAnimalName(animal) << " has " << *legs << " legs.\n";
}

int main()
{
    Animal cat{ Animal::cat };
    Animal chicken{ Animal::chicken };

    printNumberOfLegs(cat);
    printNumberOfLegs(chicken);

    return 0;
}
