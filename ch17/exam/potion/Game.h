#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

class Game
{
public:
    void setup();
    void play();
    void close();


private:    
    static constexpr int s_minGold{ 80 };
    static constexpr int s_maxGold{ 120 };

    Player m_player{ };

    struct Player
    {
        std::string name{ };
        int gold{ };
        std::vector<int> inventory{ };
    };
};

#endif