#include "Game.h"
#include <iostream>

int main()
{
    Game game{ };

    game.setup();
    std::cout << '\n';

    game.play();
    std::cout << '\n';

    game.close();
    std::cout << '\n';

    return 0;
}