#include <iostream>
#include "Deck.h"
#include "CardHand.h"
#include "PokerScore.h"
#include "CardHandScorer.h"
int main() {

    Deck deck; // creates deck and shuffles the cards inside
    std::cout << "Deck\n";
    std::cout << deck; // outputs the deck contents

    CardHand hand; // creates the players hand
    std::cout << "\nhand\n";


    // add 5 cards to the players hand
    for (int i = 0; i < 5; i++)
        if (hand.size() < 5)
            //hand.addCard(Card(HEARTS, ACE));
            hand.addCard(deck.dealCard());

    std::cout << "\nUsing showHand with sort\n";
    hand.sort();
    hand.showHand();

    //analyze card hand and get poker scores
    PokerScore pokerScore = CardHandScorer::handScore(hand);



    return 0;
}
