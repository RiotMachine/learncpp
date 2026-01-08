// return by reference

#include <iostream>
#include <string>

const std::string& getProgramName()
{
    static const std::string name { "My program" };
    return name;
}

void launchProgram(const std::string& name)
{
    if (name == "My program")
        std::cout << "Yay!\n";
}

int main()
{
    std::string program{ getProgramName() };
    launchProgram(program);

    return 0;
}

