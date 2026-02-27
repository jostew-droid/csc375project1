#include "Deck.h"

template <typename T> Deck<T>::Deck() {
    list = new LinkedList<T>;
}

template <typename T> void Deck<T>::push (T item)
    {
        list->insertFront(item);
    }

template <typename T> void Deck<T>::pop () {
    list->removeNode(list->head);
}

template <typename T> bool Deck<T>::isEmpty() {
    if (list->isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T> T Deck<T>::peek() {
    if (isEmpty())
    {
        cout<< "Deck is empty"<<endl;
        return NULL;
    }

    else
    {
        return list->head->data;
    }
}

template <typename T> void Deck<T>::print() {
    cout << "Your Deck of Cards:" << endl;
    list->print();
}

template<class T> Deck<T>::~Deck() {
    delete list;
}
