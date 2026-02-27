#include <iostream>
#include "LinkedList.h"

template <typename T> LinkedList<T>::LinkedList() {
    head = nullptr;
}

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

    head = temp;
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
template <typename T> void LinkedList<T>::insertBetween(T prev, T item) {
    Node<T>* before = findNode(prev);
    if (before == nullptr) {
        insertFront(item);
    }
    else {
        Node<T>* temp = new Node<T>();
        temp->data = item;
        temp->next = before->next;
        before->next = temp;
    }

}
template <typename T> Node<T>* LinkedList<T>::findNode(T item) {
    Node<T>* current = head;

    if (isEmpty()) {
        return nullptr;
    }

    while (current != nullptr) {
        if (current->data == item) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
template <typename T> T LinkedList<T>::removeNode(T item) {
    Node<T>* temp = findNode(item);
    T r;

    if (temp == nullptr) {
        r = NULL;
    }
    else {
        if (temp == head) {
            head = temp->next;
            r = temp;
            delete temp;
        }
        else {
            Node<T>* before = head;
            while (before->next != temp) {
                before = before->next;
            }

            before->next = temp->next;
            r = temp;
            delete temp;
        }
    }

    return r;
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