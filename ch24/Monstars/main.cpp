#include "Game.h"
#include <iostream>

int main()
{
    Game game{ Game::init() };
    game.play();
    game.printResults();
    std::cout << '\n';

    return 0;
}
