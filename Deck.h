//
// Created by Jessie Mejia on 11/5/22.
//

#ifndef DECKOFCARDS_DECK_H
#define DECKOFCARDS_DECK_H

#include "Card.h"
#include "RankEnum.h"
#include "SuitEnum.h"
#include <iostream>
class Deck {
private:
    int cardIndex; //marks the index of the next card in the deck
    Card deck[52];// this is your final deck of cards
    const int DECK_SIZE = 52;// this is the size of your deck
    bool empty(); //returns true if deck has no cards
    void fillDeck();

public:
    Deck(); // this is the constructor
    void shuffle(); // puts cards in random order
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index); // gets the Card at the given index
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console

};


#endif //DECKOFCARDS_DECK_H
