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
/*
 "If a parameter is passed into a function by reference, it’s safe to return that parameter by reference.
 "in order to pass an argument to a function, the argument must exist in the scope of the caller.
 "When the called function returns, that object must still exist in the scope of the caller."
*/
const int& printFive(const int& five=5)
{
    return five;
}

int main()
{
    std::string_view program{ getProgramName() };
    launchProgram(program);

    std::cout << printFive() << '\n';
    // this though leads to a dangling reference
    // since rvalue lifetime extensions dont work across function boundaries
    /// temp object holding 5 dies at end of this expression
    // const int& ref{ printFive() };

    return 0;
}

