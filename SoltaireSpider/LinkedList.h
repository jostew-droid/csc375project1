#ifndef SOLTAIRESPIDER_LINKEDLIST_H
#define SOLTAIRESPIDER_LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void sortList();
    void displaySum();
    void removeDuplicates();
    void contains(const std::string& element);
    void addLast(const std::string& element);
    bool isEmpty() const;
    void addFirst(const std::string& e);
    void add(int index, const std::string& e);
    void removeFirst();
    void removeLast();
    void remove(int index);
    void display();

    std::string getHeadElement() const;
    std::string getElementAt(int index) const;
    int getSize() const;
    std::string getLastElement();
};

#endif