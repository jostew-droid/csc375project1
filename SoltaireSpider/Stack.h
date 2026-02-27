#ifndef SOLTAIRESPIDER_STACK_H
#define SOLTAIRESPIDER_STACK_H


#include <iostream>
#include <string>
#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* head; // Must specify <T>
    Node<T>* tail; // Must specify <T>
    int size;

public:
    // Constructor
    Stack() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~Stack() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add an element to the top (Push)
    void push(const T& e) {
        Node<T>* newNode = new Node<T>(e); // Create a Node of type T
        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = head;
        }
        size++;
    }

    // Remove the top element (Pop)
    void pop() {
        if (size == 0) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Peek at the top element
    T top() const {
        if (head != nullptr) {
            return head->element;
        }
        return T();
    }

    // Display elements from top to bottom
    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->element << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};
#endif//SOLTAIRESPIDER_STACK_H