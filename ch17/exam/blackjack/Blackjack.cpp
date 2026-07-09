#include "Blackjack.h"
#include "Deck.h"
#include "Helpers.h"
#include <iostream>

int Blackjack::Player::score()
{
    int sum = 0;
    for (const auto& card : hand)
        sum += card.value();
    return sum;
}

std::ostream& Blackjack::operator<<(std::ostream& out, const Player::Hand& hand)
{
    for (const auto& card : hand)
        out << card << ' ';
    return out;
}

void Blackjack::play()
{
    Deck deck{ };
    deck.shuffle();
        
    Player dealer{{ deck.draw() }};
    Player user{{ deck.draw(), deck.draw() }};

    std::cout << "The dealer is showing: " << dealer.hand << '\n';
    std::cout << "You have: " << user.hand << '\n';

    bool userBust{ false };
    bool dealerBust{ false };

    while (!userBust)
    {
        std::cout << "h to hit, anything else to stand: ";
        if (Helpers::getChar() != 'h')
            break;
        user.hand.push_back(deck.draw());
        std::cout << "You were dealt " << user.hand.back()
            << ". You now have: " << user.score() << '\n';
        if (user.score() > maxScore)
        {
            userBust = true;
            std::cout << "You went bust.\n";
        }
    }

    while (dealer.score() < dealerMinScore && !userBust)
    {
        dealer.hand.push_back(deck.draw());
        std::cout << "The dealer flips a " << dealer.hand.back()
            << ". They now have: " << dealer.score() << '\n';
        if (dealer.score() > maxScore)
        {
            dealerBust = true;
            std::cout << "The dealer went bust.\n";
        }
    }

    if ( userBust || (!dealerBust && user.score() < dealer.score()) )
        std::cout << "You lose.\n";
    else if (dealer.score() == user.score())
        std::cout << "You tie.\n";
    else
        std::cout << "You win!\n";
}