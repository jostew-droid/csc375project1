#include "LinkedList.h"
#include <iostream>
using namespace std;

//Insert item in front of list
template <typename T> void LinkedList<T>::insertFront(T item) {
    Node<T>* temp = new Node<T>();
    temp->data = item;

    if (LinkedList<T>::isEmpty()) {
        temp->next = nullptr;
    }
    else {
        temp->next = head;
    }
}
//Insert item at back of list
template <typename T> void LinkedList<T>::insertBack(T item) {
    if (isEmpty()) {
        LinkedList<T>::insertFront(item);
    }
    else {
        Node<T>* temp = new Node<T>();
        temp->data = item;

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = temp;
        temp->next = nullptr;
    }
}
//Insert item at specified index
template <typename T> void LinkedList<T>::insertIndex(int index, T item) {

}
template <typename T> T LinkedList<T>::popFront() {

}
template <typename T> T LinkedList<T>::popBack() {

}
template <typename T> T LinkedList<T>::popIndex() {

}

template <typename T> int LinkedList<T>::getSize() {
    int length = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}
//Return true if the head of the list is null
template <typename T> bool LinkedList<T>::isEmpty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}
template <typename T> void LinkedList<T>::print() {
    int num = 0;
    Node<T>* current = head;
    if (LinkedList<T>::isEmpty()) {
        cout << "The list is empty!" << endl;
    }

    while (current != nullptr) {
        cout << "Node " << num << " : " << current->data << endl;
        current = current->next;
        num++;
    }
}