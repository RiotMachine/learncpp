#ifndef CARD_H
#define CARD_H

#include <array>
#include <iostream>
#include <string>

struct Card
{
    enum Rank
    {
        ace, 
        two=2,   three=3, four=4, 
        five=5,  six=6,   seven=7, 
        eight=8, nine=9,  ten=10, 
        jack,    queen,   king,
    };

    enum Suit
    {
        club, diamond,
        heart, spade,
    };

    Rank rank{ };
    Suit suit{ };

    constexpr static int max_ranks{ 13 };
    constexpr static std::array ranks{
        ace,
        two, three, four, 
        five, six, seven, 
        eight, nine, ten, 
        jack, queen, king
    };
    static_assert(ranks.size() == max_ranks);

    constexpr static int max_suits{ 4 };
    constexpr static std::array suits{
        club, diamond,
        heart, spade
    };
    static_assert(suits.size() == max_suits);

    constexpr int value() const
    {
        switch (rank)
        {
        case ace:   return 11;
        case jack:
        case queen:
        case king:  return 10;
        default:    return static_cast<int>(rank);
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Rank rank)
    {
        switch (rank)
        {
        case ace:   return out << 'A';
        case jack:  return out << 'J';
        case queen: return out << 'Q';
        case king:  return out << 'K';
        default:    return out << std::to_string(rank);
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Suit suit)
    {
        switch (suit)
        {
        case club:    return out << 'C';
        case diamond: return out << 'D';
        case heart:   return out << 'H';
        case spade:   return out << 'S';
        default:      return out << '?';
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        return out << card.rank << card.suit;
    }
};

#endif