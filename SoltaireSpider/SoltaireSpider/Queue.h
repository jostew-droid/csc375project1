#ifndef SOLTAIRESPIDER_QUEUE_H
#define SOLTAIRESPIDER_QUEUE_H

#include <iostream>
#include <string>
#include "Node.h"


#include <iostream>
#include <string>

template <typename T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;
        Node(const T& e) : element(e), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add an element to the end of the queue (Enqueue)
    void enqueue(const T& element) {
        Node* temp = new Node(element);
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

        Node* temp = head;
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
        return T(); // Returns default (e.g., "" for string, 0 for int)
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif //SOLTAIRESPIDER_QUEUE_H