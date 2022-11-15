//
// Created by Jessie Mejia on 11/5/22.
//

#include "Card.h"
#include "RankEnum.h"
#include "SuitEnum.h"
#include <iostream>

std::string Card::rankToString() const {
    switch (rank) {
        case ACE: return  "Ace";
        case KING: return  "King";
        case QUEEN: return  "Queen";
        case JACK: return  "Jack";
        case TEN: return  "Ten";
        case NINE: return  "Nine";
        case EIGHT: return  "Eight";
        case SEVEN: return  "Seven";
        case SIX: return  "Six";
        case FIVE: return  "Five";
        case FOUR: return  "Four";
        case THREE: return  "Three";
        case TWO: return  "Two";
    }
}

std::string Card::suitToString() const {
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
    }
}
void Card::setSuit(SuitEnum value){
    suit = value;
}

void Card::setRank(RankEnum value) {
    rank = value;
}

SuitEnum Card::getSuit() {
    return suit;
}

RankEnum Card::getRank() {
    return rank;
}

Card::Card(SuitEnum value, RankEnum string) {
    suit = value;
    rank = string;
}

Card::Card() : Card(HEARTS, ACE) {}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    out << card.rankToString() + " of " +  card.suitToString() << std::endl;
    return out;
}

bool operator>(const Card &firstCard, const Card &secondCard) {
    return firstCard.rank > secondCard.rank;
}

bool operator<(const Card &firstCard, const Card &secondCard) {
    return firstCard.rank < secondCard.rank;
}
bool operator==(const Card &firstCard, const Card &secondCard) {
    return firstCard.rank == secondCard.rank;
}

bool operator==(const Card &firstCard, const int &n ) {
    return firstCard.rank == n;
}

int operator+(const Card &firstCard, const int &n) {
    return firstCard.rank + n;
}

int operator+(const int &n, const Card &firstCard) {
    return firstCard.rank + n;
}

bool operator==(const int &n, const Card &firstCard) {
    return firstCard.rank == n;
}

