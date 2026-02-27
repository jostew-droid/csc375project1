#include "Stack.h"

// Constructor
Stack::Stack() : head(nullptr), tail(nullptr), size(0) {}

// Add a string to the top (beginning of the list)
void Stack::push(const std::string& e) {
    Node* newNode = new Node(e);
    newNode->next = head;
    head = newNode;

    if (size == 0) {
        tail = head;
    }
    size++;
}

// Remove the top string
void Stack::pop() {
    if (size == 0) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

// Peek at the top string without removing it
std::string Stack::top() const {
    if (head != nullptr) {
        return head->element;
    }
    return "";
}

// Display the elements from top to bottom
void Stack::display() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "\"" << temp->element << "\" ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Destructor
Stack::~Stack() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}