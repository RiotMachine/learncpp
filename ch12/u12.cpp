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

int main()
{
    std::string_view program{ getProgramName() };
    launchProgram(program);

    return 0;
}

