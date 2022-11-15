//
// Created by Jessie Mejia on 11/5/22.
//

#include "Deck.h"
#include "Card.h"
#include <cstdlib>
#include <iostream>

Deck::Deck() {
    fillDeck();
    shuffle();
}

void Deck::fillDeck() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            // creates a deck of cards using the given enums
            deck[cardIndex++] = Card(SuitEnum(i), RankEnum(j));
        }
    }
    cardIndex--;
}

void Deck::shuffle()
{
    for (int i = 0; i < DECK_SIZE; i++){
        int random = rand() % DECK_SIZE;
        Card temp = deck[random];
        deck[random] = deck[0];
        deck[0] = temp;
    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) // prints all the cards to the console
{
    for (int i = 0; i < deck.DECK_SIZE; i++)
    {
        out << i + 1 << ": " << deck.deck[i];
    }
    return out;
}

Card Deck::dealCard() {
    std::cout << deck[cardIndex--];
    return deck[cardIndex--];
}

Card Deck::getCardAt(int index) {
    return deck[index];
}

bool Deck::empty() {
    return false;
}
