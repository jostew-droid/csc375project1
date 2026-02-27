#include "Deck.cpp"
using namespace std;


bool test1() {
    cout << "------Test 1------" << endl;
    LinkedList<int>* myList = new LinkedList<int>();
    bool result = true;

    for (int i = 0; i < 10; i++) {
        myList->insertFront(i);
    }
    myList->print();
    for (int i = 0; i < 10; i++) {
        Node<int>* check = myList->findNode(i);
        if (check == nullptr) {
            result = false;
            cout << "Failed to get data in node" << i << endl;
        }
        else {
            cout <<"Found node: " << check->data << endl;
        }
    }
    delete myList;
    cout << "Test 1 Success?: " << result << endl;
    return result;
}

bool test2() {
    cout << "------Test 2------" << endl;
    Deck<string>* myDeck = new Deck<string>();
    bool result = true;
    string suit = "";
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                suit = "S";
                break;
            case 1:
                suit = "C";
                break;
            case 2:
                suit = "D";
                break;
            case 3:
                suit = "H";
                break;
            default:
                suit = "Z";
                break;
        }
        myDeck->push("A" + suit);
        for (int j = 2; j < 11; j++) {
            myDeck->push(to_string(j) + suit);
        }
        myDeck->push("J" + suit);
        myDeck->push("Q" + suit);
        myDeck->push("K" + suit);
    }
    myDeck->print();
    return result;
}


void runLinkedListTests() {
    // test1();
    test2();
}


int main() {
    runLinkedListTests();
}