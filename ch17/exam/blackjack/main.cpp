#include "Card.h"
#include <iostream>

int main()
{
    Card card{ Card::five, Card::heart };
    std::cout << card << '\n';

    for (const auto suit : Card::suits)
    {
        for (const auto rank : Card::ranks)
            std::cout << Card {rank, suit} << ' ';
    }
    std::cout << '\n';

    return 0;
}