#ifndef GAME_H
#define GAME_H

class Game
{
public:
    bool play();

private:
    static std::string getName();

    Game(std::string_view name)
      : m_player{ name } m_monster{ Monster::getRandomMonster() } {}

    void fight(Monster);

    Player m_player;
}

#endif

1. get config
2. init game
3. loop while usr lvl < 20 && user != dead
     assign a monster
     take usr input
       flee

       run

