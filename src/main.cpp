#include <iostream>
#include "LLTests.cpp"
#include "LinkedList.cpp"
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


void runLinkedListTests() {
    test1();
}


int main() {
    runLinkedListTests();
}