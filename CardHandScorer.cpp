//
// Created by Jessie Mejia on 11/9/22.
//
#include "CardHand.h"
#include "CardHandScorer.h"

PokerScore CardHandScorer::handScore(CardHand playerHand) {
    playerHand.sort();
    PokerScore scr;

    if(PokerScore::highCard(playerHand) == 1) scr.addScore(PokerScore::HIGH_CARD);
    if(PokerScore::onePair(playerHand) == 1) scr.addScore(PokerScore::ONE_PAIR);
    if(PokerScore::twoPair(playerHand) == 1) scr.addScore(PokerScore::TWO_PAIR);
    if(PokerScore::threeOfAKind(playerHand) == 1) scr.addScore(PokerScore::THREE_OK_A_KIND);
    if(PokerScore::straight(playerHand) == 1) scr.addScore(PokerScore::STRAIGHT);
    if(PokerScore::flush(playerHand) == 1) scr.addScore(PokerScore::FLUSH);
    if(PokerScore::fullHouse(playerHand) == 1) scr.addScore(PokerScore::FULL_HOUSE);
    if(PokerScore::fourOfAKind(playerHand) == 1) scr.addScore(PokerScore::FOUR_OF_A_KIND);
    if(PokerScore::straightFlush(playerHand) == 1) scr.addScore(PokerScore::STRAIGHT_FLUSH);
    if(PokerScore::royalFlush(playerHand) == 1) scr.addScore(PokerScore::ROYAL_FLUSH);

    return scr;
}

void CardHandScorer::sort(CardHand &hand) {
    hand.sort();
}

