#include <array>
#include <iostream>

// std::array uses aggregate initialization
// explicitly value-initialize an std::array even w/o init values
/// otherwise elements will be default initialized

int main()
{
    constexpr int yearLen{ 365 };
    [[maybe_unused]] std::array<double, yearLen> dailyTemp{ };

    constexpr std::array word{ 'h', 'e', 'l', 'l', 'o' };
    std::cout << word[1] << '\n';

    return 0;
}
