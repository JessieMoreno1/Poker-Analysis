//
// Created by Jessie Mejia on 11/9/22.
//
#include <vector>
#include "Card.h"
#include "Deck.h"
#ifndef DECKOFCARDS_CARDHAND_H
#define DECKOFCARDS_CARDHAND_H


class CardHand {
public:
    void sort();
    CardHand() : cardIndex(0){}
    void addCard(Card card);
    int size() const;
    void showHand();

    Card getCardAt(int index) const;

private:
    std::vector<Card> playerHand; // cards that the player currently has
    int cardIndex;
    friend std::ostream& operator<<(std::ostream& out, const CardHand& playerHand);

};



#endif //DECKOFCARDS_CARDHAND_H
