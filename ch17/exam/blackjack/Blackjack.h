#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"
#include <vector>

namespace Blackjack
{
    struct Player
    {
        using Hand = std::vector<Card>;
        Hand hand{ };
        bool wentBust{ false };

        int score();
    };

    inline constexpr int maxScore{ 21 };
    inline constexpr int dealerMinScore{ 17 };

    std::ostream& operator<<(std::ostream& out, const Player::Hand& hand);
    void play();
}

#endif