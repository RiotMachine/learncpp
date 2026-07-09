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

        int score();
    };

    constexpr int maxScore{ 21 };
    constexpr int dealerStopScore{ 17 };

    std::ostream& operator<<(std::ostream& out, const Player::Hand& hand);
    void play();
}

#endif