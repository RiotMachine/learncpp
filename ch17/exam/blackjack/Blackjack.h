#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include <vector>

namespace Blackjack
{
    constexpr int maxScore{ 21 }
    constexpr int dealerStopScore{ 17 };

    struct Player
    {
        std::vector<Card> hand{ };

        int score()
        {
            int sum = 0;
            for (const auto& card : hand)
                sum += card.value();
            return sum;
        }
    }

    void play()
    {
        Deck deck{ };
        deck.shuffle();
        
        Player dealer{{ deck.draw() }};
        Player user{{ deck.draw(), deck.draw() }};

        std::cout << "The dealer is showing: " << dealer.score() << '\n';
        std::cout << "You have score: " << user.score() << '\n';

        while (user.score() < maxScore)
        {
            char input{ };
            std::cout << "(h) to hit, or (s) to stand: "
            std::cin >> input;
            if (input == 'h')
                break;
            user.hand.push_back(deck.draw());
            std::cout << "You were dealt " << user.hand.back()
                << ". You now have: " << user.score() << '\n';
            if (user.score() > maxScore)
                std::cout << "You went bust.\n";
        }

        while (dealer.score() <= dealerStopScore)
        {
            dealer.hand.push_back(deck.draw());
            std::cout << "The dealer flips a " << dealer.hand.back()
                << ". They now have: " << dealer.score() << '\n';
            if (dealer.score() > maxScore)
                std::cout << The dealer went bust.\n";
        }

        if (
            dealer.score() > maxScore 
            || ( user.score() < maxScore && user.score() > dealer.score() )
        )
            std::cout << "You win!\n";
        else
            std::cout << "You lose!\n";
    }
}

#endif