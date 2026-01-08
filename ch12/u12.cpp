// return by reference

#include <iostream>
#include <string>
#include <string_view>

const std::string_view getProgramName()
{
    static const std::string name { "My program" };
    return name;
}

void launchProgram(const std::string_view name)
{
    if (name == "My program")
        std::cout << "Yay!\n";
}

// 5 is in main's scope so it lives until the end of the expression in main
// if 5 itself were returned, it would die then the returned reference would be dangling
/// [technically, the refs are to a temp object holding the rvalue 5]
const int& printFive(const int& five=5)
{
    return five;
}

int main()
{
    std::string_view program{ getProgramName() };
    launchProgram(program);

    std::cout << printFive() << '\n';

    return 0;
}

