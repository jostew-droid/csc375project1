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
    // Printing Foundational/Sorted Pile
    cout << left << setw(15) << "Heart Pile: [   ] " << "Diamond Pile: [   ] " << "Spade Pile: [   ] " << "Clubs Pile: [   ]" <<endl;

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
    // functionality yet to add
    cout << left << setw(15) << "[1] Flip Cards: " << " [2] Move card to Sort Pile:" <<" [3] Move cards in Pile or Discard: [   ]" <<  endl;
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
    Card foundations[4];
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

    int srcCol, numToMove, dest;
    cout << "\nMove format: [Source 1-10] [HowMany 1-y] [Dest 1-10]";
    cout << "\nEnter move (or 0 0 0 to quit): ";

    if (!(cin >> srcCol >> numToMove >> dest)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    if (srcCol == 0) break;

    // Adjust to 0-based indexing
    srcCol--;
    dest--;

    // 1. Basic Boundary Check
    if (srcCol >= 0 && srcCol < 10 && dest >= 0 && dest < 10 && columns[srcCol].getSize() >= numToMove) {

        bool validStack = true;
        int startIndex = columns[srcCol].getSize() - numToMove;

        // 2. CHECK: Is the stack being picked up a valid Spider sequence?
        // Must be face-up, same suit, and descending rank (e.g., 7H, 6H, 5H)
        for (int i = 0; i < numToMove; i++) {
            int currentIdx = startIndex + i;

            // Cannot move hidden cards
            if (currentIdx < flippedIndex[srcCol]) {
                validStack = false;
                break;
            }

            // If moving more than one, check sequence logic
            if (i > 0) {
                Card current = columns[srcCol].getElementAt(currentIdx);
                Card previous = columns[srcCol].getElementAt(currentIdx - 1);

                if (current.suit != previous.suit || current.rank != previous.rank - 1) {
                    validStack = false;
                    break;
                }
            }
        }

        // 3. CHECK: Can the top card of our moving stack land on the destination?
        if (validStack) {
            Card movingCard = columns[srcCol].getElementAt(startIndex);
            if (!columns[dest].isEmpty()) {
                Card targetCard = columns[dest].getLastElement();
                if (!movingCard.canPlaceOn(targetCard)) {
                    validStack = false;
                }
            }
        }

        // 4. EXECUTION: If all checks pass, move the cards
        if (validStack) {
            Stack<Card> moveBuffer;

            // Pull cards off the column and into the buffer
            for (int i = 0; i < numToMove; i++) {
                moveBuffer.push(columns[srcCol].getLastElement());
                columns[srcCol].removeLast();
            }

            // Pour buffer into the destination column
            while (!moveBuffer.isEmpty()) {
                columns[dest].addLast(moveBuffer.top());
                moveBuffer.pop();
            }

            // Flip the card underneath if it was hidden
            if (columns[srcCol].getSize() > 0 && (columns[srcCol].getSize() - 1) < flippedIndex[srcCol]) {
                flippedIndex[srcCol] = columns[srcCol].getSize() - 1;
            }
        }
        else
            {
            cout << "\nIllegal Move! Check sequence rules. Press Enter...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } else
        {
        cout << "\nInvalid Input! Check column numbers/sizes. Press Enter...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}
    cout << "\nReturning to menu...\n";
    pause();
}

// Main menu options
void showMenu()
{
    cout << "\n1. Start New Game\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";
    cout << "\nChoose an option: ";
}

// Entry point for the program
int main()
{
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