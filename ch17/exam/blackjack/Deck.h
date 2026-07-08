#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Random.h"
#include <algorithm>
#include <array>

class Deck
{
public:
    Deck()
    {
        std::size_t i{ 0 };
        for (const auto suit : Card::suits)
        {
            for (const auto rank : Card::ranks)
                m_deck[i++] = Card {rank, suit};
        }
    }

    Card draw()
    {
        if (m_topIdx >= s_size)
            shuffle();
        return m_deck[m_topIdx++]; 
    }

    void shuffle() 
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        m_topIdx = 0;
    }

private:
    constexpr static int s_size = Card::suits.size() * Card::ranks.size();
    std::array<Card, s_size> m_deck{ };
    std::size_t m_topIdx{ 0 };
};

#endif