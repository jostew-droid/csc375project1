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

// Clears the terminal based on the OS
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Simple pause to keep the screen from closing immediately
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Display game header
void showTitle() {
    cout << "====================================\n";
    cout << "      Group 1 Spyder SOLITAIRE      \n";
    cout << "====================================\n";
}

// Main logic to render the 10 piles vertically side-by-side
void displayBoard(LinkedList columns[10], int flippedIndex[10]) {
    clearScreen();
    showTitle();

    // Find the longest column to know how many rows to print
    int maxHeight = 0;
    for (int i = 0; i < 10; i++) {
        if (columns[i].getSize() > maxHeight) maxHeight = columns[i].getSize();
    }

    // Print column headers P1 through P10
    for (int i = 1; i <= 10; i++) {
        cout << left << setw(8) << "P" + to_string(i);
    }
    cout << "\n--------------------------------------------------------------------------------\n";

    // Loop through rows first, then columns to print vertically
    for (int r = 0; r < maxHeight; r++) {
        for (int c = 0; c < 10; c++) {
            string card = columns[c].getElementAt(r);

            if (card != "") {
                string toPrint;
                // Check if card is face-down based on the flipped index
                if (r < flippedIndex[c]) {
                    toPrint = "  ? ";
                }
                // Check if it's the bottom card of the pile
                else if (r == columns[c].getSize() - 1) {
                    toPrint = " " + card + " ";
                }
                // It's a face-up card in a sequence
                else {
                    toPrint = " " + card;
                }
                // Use fixed width of 8 to keep the columns aligned
                cout << left << setw(8) << toPrint;
            } else {
                // Print empty space for shorter piles
                cout << setw(8) << " ";
            }
        }
        cout << "\n";
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Deck: [|||]" << "Discard: [   ]" << endl;
}

// Basic rules display
void showInstructions() {
    clearScreen();
    showTitle();
    cout << "\nInstructions:\n";
    cout << "- This is a console version of Solitaire (Spider).\n";
    cout << "- Move cards between tableau columns.\n";
    cout << "- Build foundation piles from Ace to King.\n";
    cout << "- Goal: Move all cards to foundation piles.\n";
    pause();
}

// Main game logic loop
void startGame() {
    clearScreen();
    showTitle();

    int numSuits;
    // Input validation for difficulty level
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

    // Setup deck and lists
    Deck myDeck(numSuits);
    myDeck.shuffle();

    LinkedList columns[10];
    int flippedIndex[10];
    LinkedList stock;
    myDeck.loadIntoList(stock);

    cout << "Dealing cards...\n";

    // Initial deal of 54 cards across the 10 columns
    for (int i = 0; i < 54; ++i) {
        int colIndex = i % 10;
        string cardToDeal = stock.getHeadElement();

        if (cardToDeal != "") {
            columns[colIndex].addLast(cardToDeal);
            stock.removeFirst();
        }
    }

    // Set face-up index to the last card of each pile initially
    for (int i = 0; i < 10; i++) {
        flippedIndex[i] = columns[i].getSize() - 1;
    }

    // Gameplay movement loop
    bool gaming = true;
    while (gaming) {
        displayBoard(columns, flippedIndex);

        int src, dest;
        cout << "\nEnter move (Source [1-10] Destination [1-10]) or '0 0' to quit: ";

        // Handle non-numeric input
        if (!(cin >> src >> dest)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (src == 0) break; // Exit to menu

        // Adjust 1-10 input to 0-9 for array indexing
        src--;
        dest--;

        // Validate pile indices and move the card
        if (src >= 0 && src < 10 && dest >= 0 && dest < 10 && !columns[src].isEmpty()) {
            string card = columns[src].getLastElement();

            columns[dest].addLast(card);
            columns[src].removeLast();

            // Auto-flip the next card if the last face-up card was moved
            if (columns[src].getSize() > 0 && flippedIndex[src] >= columns[src].getSize()) {
                flippedIndex[src] = columns[src].getSize() - 1;
            }
        } else {
            cout << "\nInvalid Move! Press Enter to try again...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }

    cout << "\nReturning to menu...\n";
    pause();
}

// Simple menu display
void showMenu() {
    cout << "\n1. Start New Game\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";
    cout << "\nChoose an option: ";
}

// Main entry point
int main() {
    int choice;
    bool running = true;

    while (running) {
        clearScreen();
        showTitle();
        showMenu();

        cin >> choice;

        // Catch bad input in main menu
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