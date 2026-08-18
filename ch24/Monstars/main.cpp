#include "MonsterGame.h"
#include <iostream>

int main()
{
    MonsterGame game{ MonsterGame::init() };
    std::cout << '\n';
    game.play();
    game.printResults();
    std::cout << '\n';

    return 0;
}
