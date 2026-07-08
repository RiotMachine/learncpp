#include "Deck.h"
#include <iostream>

template <int N>
void deal(Deck& deck)
{
    for (int i{ 0 }; i < N; ++i)
        std::cout << deck.draw() << ' ';
    std::cout << '\n';
}

int main()
{
    Deck deck{ };
    deal<3>(deck);
    deck.shuffle();
    deal<3>(deck);

    return 0;
}