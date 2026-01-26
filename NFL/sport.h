#ifndef SPORT_H
#define SPORT_H

#include <iostream>
#include <limits>
#include <vector>

namespace Sport
{
    enum class WlResult
    {
        win,
        loss,
    };

    enum class WltResult
    {
        win,
        loss,
        tie,
    };

    std::ostream& operator<<(std::ostream&out, WlResult result);
    std::ostream& operator<<(std::ostream&out, WltResult result);


    template <typename T, typename U>
    struct Game
    {
        T opponent{ };
        U result{ };
        int score{ };
        int opponentScore{ };

        void print() const
        {
            std::cout << opponent << ": " << result << " "
                << score << "-" << opponentScore << '\n';
        }
    };


    template <typename T, typename U, typename V>
    struct Season
    {
        T team;
        std::vector<U> regSeason;
        std::vector<V> playoffs;

        void print() const
        {
            std::cout << "Regular season:\n";
            for (const U& game : regSeason)
                game.print();
            if (!playoffs.empty())
            {
                std::cout << "Playoffs:\n";
                for (const V& game : playoffs)
                    game.print();
            }
            else
                std::cout << "The " << team << " did not make the playoffs.\n";
        }

        void search() const
        {
            std::cout << "Input a team: ";
            T opponent{ };
            if (std::cin >> opponent)
            {
                bool flag{ true };
                for (const U& game : regSeason)
                    if (game.opponent == opponent)
                    {
                        flag = false;
                        game.print();
                    }
                for (const V& game : playoffs)
                    if (game.opponent == opponent)
                    {
                        flag = false;
                        game.print();
                    }
                if (flag)
                    std::cout << "Your team did not play the " << opponent << '\n';
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That is not an valid team.\n";
            }
        }
    };
}

#endif
