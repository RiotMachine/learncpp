// std::optional for optional parameters
/// prefer std::optional<T> over pointer to const defaulting to nullptr
//// only when T would normally be passed by value (ie. is inexpensive to copy)
/// remember that one can often better handle optional parameters
//// through overloads

#include <iostream>
#include <optional>

/*
void printID(std::optional<const int> id=std::nullopt)
{
    if (id)
        std::cout << "That user exists.\n";
    else
        std::cout << "That user does not exist.\n";
}
*/

void printID()
{
    std::cout << "That user does not exist.\n";
}

void printID(const int& x)
{
    std::cout << "That user exists.\n";
}

int main()
{
    printID();
    int user{ 0 };
    printID(user);
    printID(7);

    return 0;
}
