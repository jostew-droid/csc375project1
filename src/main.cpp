#include <iostream>
#include "LinkedList.cpp"

int main() {
    LinkedList<string> myList;
    myList.insertFront("Hello World");
    myList.insertBack(", I'm a list!");
    cout << myList.getSize() << endl;
    myList.print();
}