#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void fizzbuzz(int testSize)
{
    static const std::vector divisors{
        3, 5, 7, 11, 13, 17, 19
        };

    static const std::vector<std::string_view> words{
        "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"
        };

    assert(
        divisors.size() == words.size()
        );

    for (int i{ 1 }; i <= testSize; ++i)
    {
        bool printed{ false };
        for (std::size_t j{ 0 }; j < divisors.size(); ++j)
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                printed = true;
            }
        if (!printed)
            std::cout << i;
        std::cout << '\n';
    }
}

int main()
{
    constexpr int testSize{ 150 };
    fizzbuzz(testSize);

    return 0;
}
