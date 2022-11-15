//
// Created by Jessie Mejia on 11/9/22.
//

/*
 * This file is in charge of managing the Scores related to
 * the game of poker. It iterates through the players hand
 * and compares it to the different potential hands that are
 * allowed in the game of poker then adds to a counter if there
 * is a valid pair.
 */
#include "PokerScore.h"
#include "CardHand.h"
#include "Deck.h"
#include "Card.h"
#include <vector>

// vector is in charge of keeping track of how many times a valid
// hand rank occurs in our players hand.
std::vector<int> scores(10);

/*
 * This function checks if the players hand is a Royal Flush.
 * A royal flush is a hand that contains an (A)ce, (K)ing, (Q)ueen,
 * (J)ack, Ten (10) and the cards contain the same suit.
 *
 * if all of the above is true then this function returns true
 * for this players hand, otherwise it returns false. And moves on
 * to check if the player contains a different valid ranking for the
 * game of poker.
 */
bool PokerScore::royalFlush(CardHand hand) {
    hand.sort();
    if (
            (hand.getCardAt(0) == RankEnum::ACE) &&
            (hand.getCardAt(1) == RankEnum::KING) &&
            (hand.getCardAt(2) == RankEnum::QUEEN) &&
            (hand.getCardAt(3) == RankEnum::JACK) &&
            (hand.getCardAt(4) == RankEnum::TEN)
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * This function is checking if the players hand
 * contains 4 cards that contain the same rank.
 * we use the first card as reference and then iterate
 * through the hand to see if there are 3 other matches to
 * the rank of the first card.
 *
 * If the condition is met and there are 4 cards then the
 * function returns true. otherwise it will return false
 */
bool PokerScore::fourOfAKind(CardHand hand) {
    // four cards of the same ranking
    int count = 1;
    RankEnum rankToFind = hand.getCardAt(0).getRank();
    for (int i = 1; i < hand.size() - 1; i++)
    {
        if (hand.getCardAt(i) == rankToFind)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * This function returns true if there are 3 ranks that are matching and 2 other
 * ranks that are matching, this takes into account the different positions that
 * they can be at. If there is 3 of one rank and 2 of a different rank then this
 * condition is met.
 *
 * if the condition is not met then this function returns false.
 */
bool PokerScore::fullHouse(CardHand hand) {
    // three cards of the same rank along with two cards of the same rank
    hand.sort();
    // first three cards have same rank and the last two have their own rank
    if ((hand.getCardAt(0).getRank() == hand.getCardAt(1).getRank()) &&
    (hand.getCardAt(1).getRank() == hand.getCardAt(2).getRank()) &&
    (hand.getCardAt(3).getRank() == hand.getCardAt(4).getRank()))
    {
        return true;
    }
    // the first two cards match and the last three match ranks
    else if ((hand.getCardAt(0).getRank() == hand.getCardAt(1).getRank()) &&
             (hand.getCardAt(2).getRank() == hand.getCardAt(3).getRank()) &&
             (hand.getCardAt(3).getRank() == hand.getCardAt(4).getRank()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * in this function we are looking to find if the players
 * hand is a flush. we start by making the first card's suit
 * the suit we need to find for the rest of the players hand.
 *
 * we iterate through the deck, starting at the second card since
 * we already know the suit of the first card. if the next card
 * has the same suit then we iterate a counter.
 *
 * In the end , this function will return true if the counter is at 4,
 * otherwise it will return false.
 */
bool PokerScore::flush(CardHand hand) {
    hand.sort();
    int count = 1;
    SuitEnum suitToFind = hand.getCardAt(0).getSuit();
    for (int i = 1; i < hand.size(); i++)
    {
        if (hand.getCardAt(i).getSuit() == suitToFind)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * This function is similar to the flush function
 * except that it is looking for ranks in this function.
 *
 * If there are a total of 5 cards with the same rank, then this
 * function will return true. The counter needs to reach 4 in order
 * to be true, the reason being that we already distinguished that we
 * need to find the same rank as the first card which is assigned to
 * rankToFind. If this condition is not met, then the function returns false.
 */
bool PokerScore::straight(CardHand hand) {
    //five cards in consecutive ranking
    int count = 1;
    RankEnum rankToFind = hand.getCardAt(0).getRank();
    hand.sort();
    for (int i = 1; i < hand.size() - 1; i++)
    {
        if (hand.getCardAt(i).getRank() == rankToFind)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * This function is looking to find three cards with the same rank.
 * If the current card has the same rank as the next card and the next card
 * has the same rank as the card two spaces ahead, then the condition becomes true
 * and the function returns true.
 *
 * If the condition is not met then the function returns false.
 */
bool PokerScore::threeOfAKind(CardHand hand)
{
    //three cards of the same rank
    hand.sort();
    for (int i = 0; i < 3; i++)
    {
        if ((hand.getCardAt(i).getRank() == hand.getCardAt(i + 1).getRank()) &&
        (hand.getCardAt(i+1).getRank() == hand.getCardAt(i + 2).getRank()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

/*
 * This function is similar to the function onePair,
 * the difference in this function is that it iterates, and
 * it tries to find two pairs of cards with the same rank.
 * If there is a pair, the counter goes up by one, in order
 * for this function to return true it must find 2 pairs.
 */
bool PokerScore::twoPair(CardHand hand) {
    //two cards of the same rank along with another two cards of the same rank
    hand.sort();
    int count = 0;
    for (int i = 0; i < hand.size() - 1; i++)
    {
        if (hand.getCardAt(i).getRank() == hand.getCardAt(i + 1).getRank())
        {
            count++;
        }
    }
    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * This function is iterating through the players hand and checking
 * if the current card is the same rank as the next card. If it is not
 * then the iteration moves to the next card and does the same with the
 * card to the right of the current card. If there is a match with two cards
 * then the function returns true. If there is no match after going through the
 * hand then the function returns false and moves on.
 */
bool PokerScore::onePair(CardHand hand) {
    //two cards of the same rank
    hand.sort();
    for (int i = 0; i < hand.size() - 1; i++)
    {
        if (hand.getCardAt(i).getRank() == hand.getCardAt(i + 1).getRank())
        {
            return true;
        }
    }
    return false;
}

/*
 * This function checks if the players hand contains
 * a high card. If the player has more than one card
 * it will return the last card from the players hand.
 * Since this is a sorted hand, the last card is the
 * highest value.
 *
 * It then returns true if there is a high card, If
 * there is no high card then this function will return false.
 */
bool PokerScore::highCard(CardHand hand) {
    hand.sort();
    if (hand.size() > 0)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const PokerScore& scr){
    out << "High: " << scores.at(0) << "\n";
    out << "One Pair: " << scores.at(1) << "\n";
    out << "Two Pair: " << scores.at(2) << "\n";
    out << "Three Kind: " << scores.at(3) << "\n";
    out << "Straight: " << scores.at(4) << "\n";
    out << "Flush: " << scores.at(5) << "\n";
    out << "Full House: " << scores.at(6) << "\n";
    out << "Four of a kind: " << scores.at(7) << "\n";
    out << "Straight Flush: " << scores.at(8) << "\n";
    out << "Royal Flush: " << scores.at(9) << "\n";
    return out;
}

void PokerScore::addScore(Scores score) {
    if(score == HIGH_CARD ) scores[0] = scores[0] + 1;
    if(score == ONE_PAIR ) scores[1] = scores[1] + 1;
    if(score == TWO_PAIR ) scores[2] = scores[2] + 1;
    if(score == THREE_OK_A_KIND ) scores[3] = scores[3] + 1;
    if(score == STRAIGHT ) scores[4] = scores[4] + 1;
    if(score == FLUSH ) scores[5] = scores[5] + 1;
    if(score == FULL_HOUSE ) scores[6] = scores[6] + 1;
    if(score == FOUR_OF_A_KIND ) scores[7] = scores[7] + 1;
    if(score == STRAIGHT_FLUSH ) scores[8] = scores[8] + 1;
    if(score == ROYAL_FLUSH ) scores[9] = scores[9] + 1;
}

bool PokerScore::straightFlush(CardHand hand) {
    if(flush(hand) && straight(hand)){
        return true;
    }
    else
    {
        return false;
    }
}
