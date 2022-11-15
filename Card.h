//
// Created by Jessie Mejia on 11/5/22.
//

#ifndef DECKOFCARDS_CARD_H
#define DECKOFCARDS_CARD_H

#include "RankEnum.h"
#include "SuitEnum.h"
#include <string>

class Card {
private:

    SuitEnum suit;
    RankEnum rank;
    friend bool operator>(const Card &firstCard, const Card &secondCard);
    friend bool operator<(const Card &firstCard, const Card &secondCard);
    friend bool operator==(const Card &firstCard, const Card &secondCard);
    friend bool operator==( const int &n, const Card &firstCard);

    friend bool operator==(const Card &firstCard, const int &n);
    friend int operator+(const Card &firstCard, const int &n);
    friend int operator+(const int &n,const Card &firstCard);
public:
    std::string rankToString() const;
    std::string suitToString() const;
    SuitEnum getSuit();
    RankEnum getRank();
    void setSuit(SuitEnum suit);
    void setRank(RankEnum value);

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    //Card(std::string value, std::string string);
    Card(SuitEnum suit, RankEnum string);
    Card();

};


#endif //DECKOFCARDS_CARD_H
