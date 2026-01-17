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

constexpr std::string_view getAnimalName(Animal animal)
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

constexpr std::optional<int> getNumberOfLegs(Animal animal)
{
    switch(animal)
    {
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:     return 4;
    case Animal::chicken:
    case Animal::duck:    return 2;
    default:              return { };
    }
}

void printNumberOfLegs(Animal animal)
{
    std::optional<int> legs{ getNumberOfLegs(animal) };
    if (!legs)
        std::cout << "What did you pass me fool?\n";
    else
        std::cout << "A " << getAnimalName(animal) << " has " << *legs
            << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}
