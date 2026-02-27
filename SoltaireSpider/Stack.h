#ifndef SOLTAIRESPIDER_STACK_H
#define SOLTAIRESPIDER_STACK_H


#include <iostream>
#include <string>

template <typename T>
class Stack {
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
    Stack() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add an element to the top
    void push(const T& e) {
        Node* newNode = new Node(e);
        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = head;
        }
        size++;
    }

    // Remove the top element
    void pop() {
        if (size == 0) return;

        Node* temp = head;
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
        return T(); // Returns default value (0 for int, "" for string)
    }

    // Display elements from top to bottom
    void display() const {
        Node* temp = head;
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