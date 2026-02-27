#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include "LinkedList.h"
#include "Card.h"

template <typename T>
class Deck {
private:
    std::vector<T> cards;

public:
    Deck(int numSuits) {
        // We assume T can be constructed from a rank and suit string
        // If T is std::string, we use Card::toString()
        std::string suitNames[] = {"S", "H", "D", "C"};

        for (int i = 0; i < 104; ++i) {
            int rank = (i % 13) + 1;
            int suitIndex = (i / 13) % numSuits;
            std::string suit = suitNames[suitIndex];

            Card tempCard(rank, suit);

            // Logic to handle different template types
            if constexpr (std::is_same_v<T, std::string>) {
                cards.push_back(tempCard.toString());
            } else {
                cards.push_back(T(rank, suit)); // Assumes T has a constructor(int, string)
            }
        }
    }

    void shuffle() {
        // We use a random_device to seed the generator
        std::random_device rd;
        std::mt19937 g(rd());

        // Modern C++ shuffle
        std::shuffle(cards.begin(), cards.end(), g);
    }

    // UPDATED: Now accepts the templated LinkedList
    void loadIntoList(LinkedList<T>& list) {
        for (const T& c : cards) {
            list.addLast(c);
        }
    }
};

#endif// SOLTAIRESPIDER_DECK_H