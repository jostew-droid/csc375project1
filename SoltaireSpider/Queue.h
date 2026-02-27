#ifndef SOLTAIRESPIDER_QUEUE_H
#define SOLTAIRESPIDER_QUEUE_H

#include <iostream>
#include <string>
#include "Node.h"

class Queue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Queue();
    ~Queue();

    // Add a string to the end of the queue
    void enqueue(const std::string& element);

    // Remove the first string from the front
    void dequeue();

    // Returns the string at the front
    std::string front() const;

    bool isEmpty() const;

    void display() const;
};

#endif //SOLTAIRESPIDER_QUEUE_H