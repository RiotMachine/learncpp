#ifndef GAME_H
#define GAME_H

class Game
{
public:
    void init();
    void shop();
    void close();

    void listPotions()
    {
        for (const auto& e : types)
        {
            const Data& potion{ data[e] };
            std::cout << static_cast<int>(e) << ") " << potion.name
                << " costs " << potion.cost << '\n';
        }
    }



private:
    User m_user{ };


    struct User
    {
        int gold{ 85 }
        std::string name{ };
        std::vector<Potion> inventory{ };
    };
}

#endif
