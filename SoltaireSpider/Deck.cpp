#include "Deck.h"
#include "Card.h"
#include <algorithm> // For std::random_shuffle or std::shuffle
#include <ctime>     // For seeding the random number generator

Deck::Deck(int numSuits) {
    // numSuits can be 1, 2, or 4
    std::string suitNames[] = {"S", "H", "D", "C"};

    for (int i = 0; i < 104; ++i) {
        int rank = (i % 13) + 1; // Always results in 1, 2, 3... 13

        // This math determines the suit:
        // (i / 13) tells us which "set" of 13 we are on (0 to 7)
        // % numSuits ensures we only use the allowed number of suits
        int suitIndex = (i / 13) % numSuits;
        std::string suit = suitNames[suitIndex];

        Card tempCard(rank, suit);
        cards.push_back(tempCard.toString());
    }
}

// Shuffle the cards
void Deck::shuffle() {
    std::srand(std::time(0));
    std::random_shuffle(cards.begin(), cards.end());
}

// Convert the vector into your LinkedList to represent the "Stock Pile"
void Deck::loadIntoList(LinkedList& list) {
    for (const std::string& c : cards) {
        list.addLast(c);
    }
}