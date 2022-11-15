//
// Created by Jessie Mejia on 11/9/22.
//

#ifndef DECKOFCARDS_POKERSCORE_H
#define DECKOFCARDS_POKERSCORE_H

#include <vector>
#include "CardHand.h"
class PokerScore {
public:
    enum Scores{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OK_A_KIND, //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD //highest card in the player’s hand

    };
public:
    static bool royalFlush(CardHand hand);
    static bool straightFlush(CardHand hand);
    static bool fourOfAKind(CardHand hand);
    static bool fullHouse(CardHand hand);
    static bool flush(CardHand hand);
    static bool straight(CardHand hand);
    static bool threeOfAKind(CardHand hand);
    static bool twoPair(CardHand hand);
    static bool onePair(CardHand hand);
    static bool highCard(CardHand hand);

    friend std::ostream& operator<<(std::ostream& out, const PokerScore& s);
    void addScore(Scores score);


};


#endif //DECKOFCARDS_POKERSCORE_H
