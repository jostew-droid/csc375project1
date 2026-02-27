//
// Created by nectricblade on 2/26/2026.
//

#ifndef SOLTAIRESPIDER_NODE_H
#define SOLTAIRESPIDER_NODE_H
#include <string>
// This class represents a node in a linked list

template <typename T>
class Node {
public:
    T element;      // Now can be string, int, Card, etc.
    Node<T>* next;  // Pointer to the next Node of the same type

    Node(const T& element)
        : element(element), next(nullptr)
    {
    }
};

#endif //SOLTAIRESPIDER_NODE_H