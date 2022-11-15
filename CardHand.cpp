//
// Created by Jessie Mejia on 11/9/22.
//

#include "CardHand.h"
#include "Card.h"
#include <iostream>
#include <algorithm>

void CardHand::addCard(Card card) {
    playerHand.push_back(card);
}

std::ostream& operator<<(std::ostream& out, const CardHand& playerHand)
{
    for (int i = 0; i < 5; i++)
    {
        //out << i + 1 << ": " << playerHand.playerHand[i].rankToString() << " of " << playerHand.playerHand[i].suitToString() << "\n";
    }
    return out;
}


int CardHand::size() const {
    return playerHand.size();
}

void CardHand::sort() {
    std::sort(playerHand.begin(), playerHand.end());
}

void CardHand::showHand() {
    for (int i = 0; i < 5; i++)
    {
        std::cout << playerHand[i];
    }
}

Card CardHand::getCardAt(int index) const {
    return playerHand[index];
}

