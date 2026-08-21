#include <array>
#include <iostream>
#include <string>
#include <string_view>

/*
  works, but
    implementation of behavior is fixed for all children
    Animal becomes a god-class
    forced to expose/hide underlying data for all children
*/

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    Animal(std::string_view name, std::string_view sound)
      : m_name{ name }, m_speak{ sound } {}

    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const   { return m_speak; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
      : Animal{ name, "meow" } {}
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
      : Animal{ name, "woof" } {}
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const std::array<const Animal*, 6> animals{
        &fred, &misty, &zeke, &garbo, &pooky, &truffle
    };

    for (const auto animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';

    return 0;
}
