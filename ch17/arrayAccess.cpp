#include <array>
#include <iostream>

int main()
{
    constexpr std::array word{ 'h', 'e', 'l', 'l', 'o' };
    std::cout << "Length: " << word.size() << '\n';
    std::cout << "At idx 1:\n"
        << "\tSubscript: " << word[1] << '\n'
        << "\tRuntime bounds checking: " << word.at(1) << '\n'
        << "\tCompile-time bounds checking: " << std::get<1>(word) << '\n';

    return 0;
}
