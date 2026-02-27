#ifndef SOLTAIRESPIDER_DECK_H
#define SOLTAIRESPIDER_DECK_H
#include "Node.h"
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
        // Spider Solitaire always uses 104 cards (2 full decks)
        std::string suitNames[] = {"S", "H", "D", "C"};

        for (int i = 0; i < 104; ++i) {
            int rank = (i % 13) + 1; //cycles 1 thru 13
            int suitIndex = (i / 13) % numSuits; // switches suit every 13th card
            std::string suit = suitNames[suitIndex];

            Card tempCard(rank, suit);

            // If we are making a Deck of strings, convert the card to a string
            if constexpr (std::is_same_v<T, std::string>) {
                cards.push_back(tempCard.toString());
            } else {
                // Otherwise, assume T is a class like Card and pass rank/suit
                cards.push_back(T(rank, suit));
            }
        }
    }

    // Modern shuffle using Mersenne Twister engine
    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    // Pours the cards from the vector into templated LinkedList
    void loadIntoList(LinkedList<T>& list) {
        for (const T& c : cards) {
            list.addLast(c);
        }
    }
};
#endif// SOLTAIRESPIDER_DECK_H