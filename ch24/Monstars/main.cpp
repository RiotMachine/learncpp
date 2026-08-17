#include "Game.h"

int main()
{
    Game game{ Game::init() };
    game.play();
    game.printResults();

    return 0;
}
