// Program to print animal data
#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_types
    };

    struct Data
    {
        std::string_view name{ };
        int legs{ };
        std::string_view sound{ };
    };

    constexpr std::array dataArr{
        Data {"chicken" , 2, "cluck"},
        Data {"dog"     , 4, "woof"},
        Data {"cat"     , 4, "meow"},
        Data {"elephant", 4, "waah"},
        Data {"duck"    , 2, "quack"},
        Data {"snake"   , 0, "hsss"}
    };

    static_assert( dataArr.size() == max_types );
}

std::istream& operator>>(std::istream& in, Animal::Data& elem)
{
    std::string input{ };
    std::getline(in >> std::ws, input);
    for (const auto& arrElem : Animal::dataArr)
    {
        if (input == arrElem.name)
        {
            elem = arrElem;
            return in;
        }
    }
    in.setstate(std::ios_base::failbit);
    elem = { };
    return in;
}

std::ostream& operator<<(std::ostream& out, const Animal::Data& elem)
{
    return out << "A " << elem.name << " has " << elem.legs
        << " legs and says " << elem.sound << '.';
}

bool operator!=(const Animal::Data& elem1, const Animal::Data& elem2)
{
    return elem1.name != elem2.name;
}

int main()
{
    std::cout << "Enter an animal you want data for: ";
    Animal::Data input{ };
    if (std::cin >> input)
        std::cout << input << "\n\n";
    else
        std::cout << "That animal couldnt be found." << "\n\n";

    std::cout << "Here is the data for the rest of the animals:\n";
    for (const auto& elem : Animal::dataArr)
        if (elem != input)
            std::cout << elem << '\n';

    return 0;
}
