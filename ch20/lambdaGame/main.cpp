#include "Game.h"

int main()
{
    Game game{ Game::setup() };
    game.play();

    return 0;
}