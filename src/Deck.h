#ifndef DECK_H
#define DECK_H
#include "LinkedList.cpp"

template<class T> class Deck {

private:
    LinkedList<T>* list;
public:
    Deck();
    ~Deck();
    void push (T item);
    void pop ();
    T peek ();

    bool isEmpty ();
    void print();

};


// //Implementation of a simple stack data structure to represent a deck of cards
// #ifndef DECK_H
// #define DECK_H
//
// #include <iostream>
// #include <new>
// using namespace std;
// #include <ostream>
//
// template<class T> class  Deck {
//     struct Node {
//         T data;
//         Node* next;
//     };
// private:
//     Node* top;
// public:
//     Deck()
//     {
//        top= nullptr;
//     }
//      bool isFull()
//     {
//         Node* temp;
//         try
//         {
//            temp = new Node;
//             delete temp;
//             return false;
//
//         }
//         catch (bad_alloc&) {
//             return true;
//         }
//     }
//
//     bool isEmpty()
//     {
//         if (top == nullptr)
//             return true;
//         else
//             return false;
//
//     }
//     void push (T item)
//     {
//         if (isFull())
//             throw bad_alloc();
//         else
//             {
//             Node* current= new Node;
//             current->data = item;
//             current->next = top;
//             top = current;
//             }
//
//     }
//
//    void pop()
//     {
//         if (isEmpty())
//         {
//          cout<<"Deck is empty"<<endl;
//         }
//         else
//         {
//             Node* temp =top;
//             top = top->next;
//             delete temp;
//         }
//     }
//
//
//     T peek()
//     {
//         if (isEmpty())
//         {
//          cout<< "Deck is empty"<<endl;
//             return ;
//         }
//
//         else
//         {
//          return top->data;
//         }
//     }
//     ~Deck() {
//         while (!isEmpty()) {
//             pop();
//         }
//     }
//
//
// };
// #endif // DECK_H
#endif // DECK_H
