#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <iomanip>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "Deck.h"
#include "LinkedList.h"

using namespace std;

// This clears the screen depending on if you're on Windows or Mac/Linux
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Just a simple pause so the terminal doesn't close too fast
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Header for the game
void showTitle() {
    cout << "====================================\n";
    cout << "      Group 1 Spyder SOLITAIRE      \n";
    cout << "====================================\n";
}

// Logic to print the 10 piles vertically so it looks like real Solitaire
void displayBoard(LinkedList<Card> columns[10], int flippedIndex[10]) {
    clearScreen();
    showTitle();

    // Need to find the tallest pile so we know how many rows to print
    int maxHeight = 0;
    for (int i = 0; i < 10; i++) {
        if (columns[i].getSize() > maxHeight) maxHeight = columns[i].getSize();
    }

    // Printing headers P1 through P10
    for (int i = 1; i <= 10; i++) {
        cout << left << setw(8) << "P" + to_string(i);
    }
    cout << "\n--------------------------------------------------------------------------------\n";

    // Double loop: Row by row, then Column by column
    for (int r = 0; r < maxHeight; r++) {
        for (int c = 0; c < 10; c++) {
            // Get the card at this specific row in this column
            Card cardObj = columns[c].getElementAt(r);

            if (cardObj.rank != 0) {
                string toPrint;
                // If the card is hidden (face-down), show a question mark
                if (r < flippedIndex[c]) {
                    toPrint = "  ? ";
                }
                // If it's the last card, show the full rank/suit
                else if (r == columns[c].getSize() - 1) {
                    toPrint = " " + cardObj.toString() + " ";
                }
                // Otherwise it's part of a face-up stack
                else {
                    toPrint = " " + cardObj.toString();
                }
                // Align everything nicely with 8 spaces
                cout << left << setw(8) << toPrint;
            } else {
                // Just empty space if the pile ended
                cout << setw(8) << " ";
            }
        }
        cout << "\n";
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Deck: [ ? ]" << "Discard: [   ]" << endl;
}

// Show the basic rules
void showInstructions() {
    clearScreen();
    showTitle();
    cout << "\nInstructions:\n";
    cout << "- Console version of Spider Solitaire.\n";
    cout << "- Move cards between columns to build sequences.\n";
    cout << "- Complete piles from Ace to King.\n";
    cout << "- Goal: Clear all cards to the foundation.\n";
    pause();
}

// This is where the actual game happens
void startGame() {
    clearScreen();
    showTitle();

    int numSuits;
    // Keep asking until they give a valid number of suits
    while (true) {
        cout << "Choose Difficulty (1, 2, or 4 suits): ";
        if (cin >> numSuits && (numSuits == 1 || numSuits == 2 || numSuits == 4)) {
            break;
        } else {
            cout << "Invalid input! Please enter 1, 2, or 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Set up the deck (templated for cards) and shuffle it
    Deck<Card> myDeck(numSuits);
    myDeck.shuffle();

    // Arrays for our 10 columns and the stock pile
    LinkedList<Card> columns[10];
    int flippedIndex[10];
    LinkedList<Card> stock;

    // Put the shuffled deck into our stock list
    myDeck.loadIntoList(stock);

    cout << "Dealing cards...\n";

    // Deal out the first 54 cards to the board
    for (int i = 0; i < 54; ++i) {
        int colIndex = i % 10;
        Card cardToDeal = stock.getHeadElement();

        if (cardToDeal.rank != 0) {
            columns[colIndex].addLast(cardToDeal);
            stock.removeFirst();
        }
    }

    // Initially, only the very last card of each pile is face-up
    for (int i = 0; i < 10; i++) {
        flippedIndex[i] = columns[i].getSize() - 1;
    }

    // Main game loop
    bool gaming = true;
    while (gaming) {
        displayBoard(columns, flippedIndex);

        int src, dest;
        cout << "\nEnter move (Source [1-10] Destination [1-10]) or '0 0' to quit: ";

        // Check if they typed numbers or something else
        if (!(cin >> src >> dest)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (src == 0) break; // Quit back to menu

        // Convert user's 1-10 into array 0-9
        src--;
        dest--;

        // Check if the move is actually possible
        if (src >= 0 && src < 10 && dest >= 0 && dest < 10 && !columns[src].isEmpty()) {
           // logic check: we can use the card class if the move is valid
           Card movingCard= columns[src].getLastElement();
            // If the destination isn't empty, we should check if the move is valid
            bool validMove = true;
            if (!columns[dest].isEmpty()) {
                Card targetCard = columns[dest].getLastElement();
                // We use our helper function from Card.h
                if (!movingCard.canPlaceOn(targetCard)) {
                    validMove = false;
                }
            }

            if (validMove) {
                columns[dest].addLast(movingCard);
                columns[src].removeLast();

                // If we moved the last visible card, flip the one under it
                if (columns[src].getSize() > 0 && (columns[src].getSize() - 1) < flippedIndex[src]) {
                    flippedIndex[src] = columns[src].getSize() - 1;
                }
            } else {
                cout << "\nIllegal Move! Cards must be in descending order. Press Enter...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }

        } else {
            cout << "\nInvalid Input! Press Enter to try again...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
    cout << "\nReturning to menu...\n";
    pause();
}

// Main menu options
void showMenu() {
    cout << "\n1. Start New Game\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";
    cout << "\nChoose an option: ";
}

// Entry point for the program
int main() {
    int choice;
    bool running = true;

    while (running) {
        clearScreen();
        showTitle();
        showMenu();

        cin >> choice;

        // Make sure the menu input is valid
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                running = false;
                break;
            default:
                cout << "\nInvalid option!";
                pause();
        }
    }

    clearScreen();
    cout << "Thank you for playing Solitaire!\n";
    return 0;
}