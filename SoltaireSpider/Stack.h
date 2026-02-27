#ifndef SOLTAIRESPIDER_STACK_H
#define SOLTAIRESPIDER_STACK_H

#include <iostream>
#include <string>
#include "Node.h"

class Stack {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Create an empty stack
    Stack();

    // Add a string to the top (beginning of the list)
    void push(const std::string& e);

    // Remove the top string
    void pop();

    // Peek at the top string without removing it
    std::string top() const;

    // Display the elements from top to bottom
    void display() const;

    // Destructor to clean up memory
    ~Stack();
};

#endif //SOLTAIRESPIDER_STACK_H