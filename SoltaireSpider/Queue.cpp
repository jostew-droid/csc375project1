#include "Queue.h"

// Constructor
Queue::Queue() : head(nullptr), tail(nullptr), size(0) {}

// Add a string to the end of the queue
void Queue::enqueue(const std::string& element) {
    Node* temp = new Node(element);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

// Remove the first string from the front
void Queue::dequeue() {
    if (size == 0) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

// Returns the string at the front
std::string Queue::front() const {
    if (head != nullptr) {
        return head->element;
    }
    return ""; // Return empty string if queue is empty
}

bool Queue::isEmpty() const {
    return size == 0;
}

void Queue::display() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "\"" << temp->element << "\" ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Destructor
Queue::~Queue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}