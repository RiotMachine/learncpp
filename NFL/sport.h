#ifndef SPORT_H
#define SPORT_H

#include <array>
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

        void print()
        {
            std::cout << opponent << ": " << result << " "
                << score << "-" << opponentScore << '\n';
        }

        void printIndent()
        {
            std::cout << '\t';
            print();
        }
    };


    template <typename T, typename U, typename V, int N>
    struct Season
    {
        T team;
        std::array<U, N> regSeasonGames;
        std::vector<V> playoffs;

        void print()
        {
            std::cout << "Regular season:\n";
            for (U game : regSeasonGames)
                game.printIndent();
            if (!playoffs.empty())
            {
                std::cout << "Playoffs:\n";
                for (V game : playoffs)
                    game.printIndent();
            }
            else
                std::cout << "\nThe " << team << " did not make the playoffs.\n";
        }

        void search()
        {
            std::cout << "\nInput a team: ";
            T opponent{ };
            if (std::cin >> opponent)
            {
                bool flag{ true };
                for (U game : regSeasonGames)
                    if (game.opponent == opponent)
                    {
                        flag = false;
                        game.print();
                    }
                for (V game : playoffs)
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
