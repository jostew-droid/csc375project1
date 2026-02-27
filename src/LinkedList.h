//Implementation of a linked list for the deck class
#include <string>
using namespace std;


template <typename T> struct Node {
    T data = "";
    Node* next;
};


template <typename T> class LinkedList{
private:
    Node<T>* head;

public:

    LinkedList() {

        head = nullptr;

    }

    //Transformers
    void insertFront(T item);
    void insertBack(T item);
    void insertIndex(int index, T item);
    T popFront();
    T popBack();
    T popIndex();
    //Aux Functions
    int getSize();
    bool isEmpty();
    void print();

};