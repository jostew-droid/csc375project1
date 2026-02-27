#ifndef SOLTAIRESPIDER_LINKEDLIST_H
#define SOLTAIRESPIDER_LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head; // Updated to Node<T>
    Node<T>* tail; // Updated to Node<T>
    int size;

public:
    // --- Constructor & Destructor ---
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // --- Addition Methods ---
    void addFirst(const T& e) {
        Node<T>* newNode = new Node<T>(e);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) tail = head;
        size++;
    }

    void addLast(const T& e) {
        Node<T>* temp = new Node<T>(e);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void add(int index, const T& e) {
        if (index <= 0) addFirst(e);
        else if (index >= size) addLast(e);
        else {
            Node<T>* current = head;
            for (int i = 1; i < index; i++)
                current = current->next;
            Node<T>* temp = current->next;
            current->next = new Node<T>(e);
            current->next->next = temp;
            size++;
        }
    }

    // --- Removal Methods ---
    void removeFirst() {
        if (size == 0) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) tail = nullptr;
    }

    void removeLast() {
        if (size == 0) return;
        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size = 0;
        } else {
            Node<T>* current = head;
            while (current->next != tail)
                current = current->next;
            delete tail;
            tail = current;
            tail->next = nullptr;
            size--;
        }
    }

    // --- Getters ---
    int getSize() const { return size; }

    bool isEmpty() const { return head == nullptr; }

    T getElementAt(int index) const {
        if (index < 0 || index >= size) return T();
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->element;
    }

    T getHeadElement() const {
        if (head == nullptr) return T();
        return head->element;
    }

    T getLastElement() const {
        if (tail == nullptr) return T();
        return tail->element;
    }

    // --- Utility ---
    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void sortList() {
        if (!head || size < 2) return;
        bool swapped = true;
        while (swapped) {
            Node<T>* temp = head;
            swapped = false;
            while (temp->next != nullptr) {
                if (temp->element > temp->next->element) {
                    T data = temp->element;
                    temp->element = temp->next->element;
                    temp->next->element = data;
                    swapped = true;
                }
                temp = temp->next;
            }
        }
        // Re-sync tail pointer after sort
        Node<T>* curr = head;
        while (curr && curr->next) curr = curr->next;
        tail = curr;
    }
};

#endif