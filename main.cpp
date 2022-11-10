#include <iostream>
#include "Card.h"
#include "Deck.h"

int main() {
    Deck deck;
    std::cout << deck;
    deck.dealCard();
    deck.getCardAt(4);

    return 0;
}
