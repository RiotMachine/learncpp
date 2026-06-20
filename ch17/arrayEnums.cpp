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

    using namespace std::string_view_literals;
    constexpr std::array dataArr{
        Data {"chicken"sv , 2, "cluck"sv},
        Data {"dog"sv     , 4, "woof"sv},
        Data {"cat"sv     , 4, "meow"sv},
        Data {"elephant"sv, 4, "waah"sv},
        Data {"duck"sv    , 2, "quack"sv},
        Data {"snake"sv   , 0, "hsss"sv}
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
    return in;
}

std::ostream& operator<<(std::ostream& out, Animal::Data elem)
{
    return out << "A " << elem.name << " has " << elem.legs
        << " legs and says " << elem.sound << '.';
}

bool operator==(Animal::Data elem1, Animal::Data elem2)
{
    return elem1.name == elem2.name;
}

int main()
{
    std::cout << "Enter an animal: ";
    Animal::Data input{ };
    if (std::cin >> input)
        std::cout << input << "\n\n";
    else
        std::cout << "That animal couldnt be found." << "\n\n";

    std::cout << "Here is the data for the rest of the animals:\n";
    for (const auto& elem : Animal::dataArr)
    {
        if (elem == input)
            continue;
        std::cout << elem << '\n';
    }

    return 0;
}
