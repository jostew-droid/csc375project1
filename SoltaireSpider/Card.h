//
// Created by nectricblade on 2/27/2026.
//

#ifndef SOLTAIRESPIDER_CARD_H
#define SOLTAIRESPIDER_CARD_H


#include <string>

class Card {
public:
    // Using integers for rank makes math/logic easy: 11=J, 12=Q, 13=K
    int rank;
    std::string suit;

    Card(int r, std::string s) : rank(r), suit(s) {}

    // A helper to turn the card into a string like "KS" or "10H"
    std::string toString() {
        std::string rankStr;
        if (rank == 1) rankStr = "A";
        else if (rank == 11) rankStr = "J";
        else if (rank == 12) rankStr = "Q";
        else if (rank == 13) rankStr = "K";
        else rankStr = std::to_string(rank);

        return rankStr + suit; // e.g., "AS" for Ace of Spades
    }

    bool isRed() {
        return (suit == "H" || suit == "D");
    }

    bool isBlack() {
        return (suit == "S" || suit == "C");
    }

    bool canPlaceOn(const Card& other) {
        return this->rank == other.rank - 1;
    }

};

#endif //SOLTAIRESPIDER_CARD_H