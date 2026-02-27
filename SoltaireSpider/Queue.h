#ifndef SOLTAIRESPIDER_QUEUE_H
#define SOLTAIRESPIDER_QUEUE_H

#include <iostream>
#include <string>
#include "Node.h"



template <typename T>
class Queue {
private:
    Node<T>* head; // Must specify <T>
    Node<T>* tail; // Must specify <T>
    int size;

public:
    // Constructor
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~Queue() {
        while (head != nullptr) {
            Node<T>* temp = head; // Added <T>
            head = head->next;
            delete temp;
        }
    }

    // Add an element to the end of the queue (Enqueue)
    void enqueue(const T& element) {
        Node<T>* temp = new Node<T>(element); // Added <T> for the constructor
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // Remove the element from the front (Dequeue)
    void dequeue() {
        if (size == 0) return;

        Node<T>* temp = head; // Added <T>
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Returns the element at the front
    T front() const {
        if (head != nullptr) {
            return head->element;
        }
        return T();
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node<T>* temp = head; // Added <T>
        while (temp != nullptr) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif //SOLTAIRESPIDER_QUEUE_H