#include "Potion.h"
#include <iostream>

int main()
{
    Potion::Game game{ Potion::Game::setup() };
    std::cout << '\n';

    game.play();
    std::cout << '\n';

    game.close();
    std::cout << '\n';

    return 0;
}