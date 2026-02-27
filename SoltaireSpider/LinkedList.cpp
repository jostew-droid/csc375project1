#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::sortList() {
    if (!head) return;
    bool swapped = true;
    while (swapped) {
        Node* temp = head;
        swapped = false;
        while (temp->next != nullptr) {
            if (temp->element > temp->next->element) {
                std::string data = temp->element;
                temp->element = temp->next->element;
                temp->next->element = data;
                swapped = true;
            }
            temp = temp->next;
        }
    }
    Node* last = head;
    while (last && last->next != nullptr) {
        last = last->next;
    }
    tail = last;
}

void LinkedList::displaySum() {
    std::string total = "";
    Node* temp = head;
    while (temp != nullptr) {
        total += temp->element;
        temp = temp->next;
    }
    std::cout << total << std::endl;
}

void LinkedList::removeDuplicates() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr->next;
        while (temp != nullptr && temp->element == curr->element) {
            Node* duplicate = temp;
            temp = temp->next;
            delete duplicate;
            size--;
        }
        curr->next = temp;
        curr = curr->next;
    }
}

void LinkedList::contains(const std::string& element) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->element == element) {
            std::cout << "The element is on the list" << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "The element is not on the list" << std::endl;
}

void LinkedList::addLast(const std::string& element) {
    Node* temp = new Node(element);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::addFirst(const std::string& e) {
    Node* newNode = new Node(e);
    newNode->next = head;
    head = newNode;
    size++;
    if (tail == nullptr)
        tail = head;
}

void LinkedList::add(int index, const std::string& e) {
    if (index <= 0)
        addFirst(e);
    else if (index >= size)
        addLast(e);
    else {
        Node* current = head;
        for (int i = 1; i < index; i++)
            current = current->next;
        Node* temp = current->next;
        current->next = new Node(e);
        current->next->next = temp;
        size++;
    }
}

void LinkedList::removeFirst() {
    if (size == 0)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    if (head == nullptr)
        tail = nullptr;
}

void LinkedList::removeLast() {
    if (size == 0) return;
    if (size == 1) {
        delete head;
        head = tail = nullptr;
        size = 0;
    } else {
        Node* current = head;
        while (current->next != tail)
            current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= size)
        return;
    else if (index == 0)
        removeFirst();
    else if (index == size - 1)
        removeLast();
    else {
        Node* previous = head;
        for (int i = 1; i < index; i++) {
            previous = previous->next;
        }
        Node* current = previous->next;
        previous->next = current->next;
        delete current;
        size--;
    }
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->element << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

std::string LinkedList::getHeadElement() const {
    if (head != nullptr) {
        return head->element;
    }
    return "";
}

std::string LinkedList::getElementAt(int index) const {
    if (index < 0 || index >= size) return "";
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->element;
}

int LinkedList::getSize() const {
    return size;
}

std::string LinkedList::getLastElement() {
    if (head == nullptr) return "";
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->element;
}