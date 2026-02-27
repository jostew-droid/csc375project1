//
// Created by nectricblade on 2/26/2026.
//

#ifndef SOLTAIRESPIDER_NODE_H
#define SOLTAIRESPIDER_NODE_H
#include <string>
// This class represents a node in a linked list

    class Node
    {
    public:
        std::string element;
        Node* next;
        Node(const std::string& element)
            : element(element), next(nullptr)
        {
        }
    };



#endif //SOLTAIRESPIDER_NODE_H