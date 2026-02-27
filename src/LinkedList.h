//Implementation of a linked list for the deck class
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

template <typename T> struct Node {
    T data;
    Node<T>* next;
};


template <typename T> class LinkedList{
private:
    Node<T>* head;

public:
    LinkedList();
    //Transformers
    void insertFront(T item);
    void insertBack(T item);
    void insertBetween(T prev, T item);
    Node<T>* findNode(T item);
    T removeNode(T item);

    //Aux Functions
    int getSize();
    bool isEmpty();
    void print();



};
#endif // LINKEDLIST_H
