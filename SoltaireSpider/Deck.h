#ifndef SOLTAIRESPIDER_DECK_H
#define SOLTAIRESPIDER_DECK_H

#include <vector>
#include <string>
#include "LinkedList.h"

class Deck {
private:
    std::vector<std::string> cards; // We use a vector here because shuffling a linked list is very slow

public:
    // numSuits can be 1, 2, or 4
    Deck(int numSuits);

    // Shuffle the cards
    void shuffle();

    // Convert the vector into your LinkedList to represent the "Stock Pile"
    void loadIntoList(LinkedList& list);
};

#endif // SOLTAIRESPIDER_DECK_H