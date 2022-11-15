//
// Created by Jessie Mejia on 11/9/22.
//

#ifndef DECKOFCARDS_CARDHANDSCORER_H
#define DECKOFCARDS_CARDHANDSCORER_H

#include "CardHand.h"
#include "Deck.h"
#include "PokerScore.h"

class CardHandScorer {

public:
    static PokerScore handScore(CardHand playerHand);
    void showScores(PokerScore &score);
    void static sort(CardHand &hand);

};


#endif //DECKOFCARDS_CARDHANDSCORER_H
