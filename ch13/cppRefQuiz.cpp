#include <iostream>
#include <string>

int main()
{
    std::string str{ "The rice is cooking" };
    str.erase(4, 11);
    // prints 'The king'
    // .erase(x, y) cuts y num of chars starting @ x
    // https://en.cppreference.com/w/cpp/string/basic_string/erase.html
    std::cout << str << '\n';

    std::string str2{ "I saw a red car yesterday." };
    // https://en.cppreference.com/w/cpp/string/basic_string/replace.html
    str2.replace(8, 3, "blue");
    std::cout << str2 << '\n';

    return 0;
}
