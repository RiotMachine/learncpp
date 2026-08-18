#ifndef MONSTERGAME_H
#define MONSTERGAME_H

#include "Game.h"

// single-player Game where Player battles Monsters

class MonsterGame : public Game
{
public:
    MonsterGame(const Player& p)
      : Game(p) {}

    static MonsterGame init();
    void play();
    void printResults();
};

#endif
