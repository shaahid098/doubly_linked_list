#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
/**
 * @class Templated DoublyLinkedList
 * @param datatype - The type of data to be stored in the list.
 */
template <typename DataType>
class DoublyLinkedList {


private:
    // struct for storing data next and prev pointers into node
    struct Node {
        DataType data;
        Node* next;
        Node* prev;
        Node(const DataType& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    //constrictor and destructor (the rule of 3)
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    // Main Methods
    void insertFront(const DataType& value); //insert value front
    void insertBack(const DataType& value); //insert value at back
    bool deleteItem(const DataType& value); //delete value
    bool isEmpty() const;   //Checks weather the list is empty
    void clear(); //clear the list
    int getLength() const; //get the number of elements

    //subclass iterator
    class Iterator {
    private:
        Node* current;
        Node* tail;

    public:
        Iterator(Node* node = nullptr, Node* tailPtr = nullptr)
            : current(node), tail(tailPtr) {}

        DataType& operator*();           // Dereference the iterator
        Iterator& operator++();          // Move to the next node
        Iterator& operator--();          // Move to the previous node
        bool operator==(const Iterator& other) const; // Check for equality
        bool operator!=(const Iterator& other) const; // Check for inequality
    };

    // Iterator Methods
    Iterator begin() const;
    Iterator end() const;
    // Overloaded Operators
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list);

};

#include "DoublyLinkedList.cpp"



// Dereference the iterator to access the current node's data.
template <typename DataType>
DataType& DoublyLinkedList<DataType>::Iterator::operator*() {
    if (!current) {
        throw std::logic_error("Iterator is out of bounds");
    }
    return current->data;
}

// Move the iterator forward to the next node.
template <typename DataType>
typename DoublyLinkedList<DataType>::Iterator& DoublyLinkedList<DataType>::Iterator::operator++() {
    if (!current) {
        throw std::logic_error("Cannot increment; iterator is at the end of the list");
    }
    current = current->next;
    return *this;
}

// Move the iterator backward to the previous node.
template <typename DataType>
typename DoublyLinkedList<DataType>::Iterator& DoublyLinkedList<DataType>::Iterator::operator--() {
    if (!current) {
        current = tail; // If the iterator is at `end()`, move to the last node.
    } else {
        current = current->prev;
    }

    if (!current) {
        throw std::logic_error("Cannot decrement; iterator is at the beginning of the list");
    }
    return *this;
}

// Compare two iterators for equality.
template <typename DataType>
bool DoublyLinkedList<DataType>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

// Compare two iterators for inequality.
template <typename DataType>
bool DoublyLinkedList<DataType>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

#endif