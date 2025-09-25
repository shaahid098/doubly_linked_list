#include "DoublyLinkedList.h"


/**
 * @brief Constructor - Initializes an empty list.
 */
template <typename DataType>
DoublyLinkedList<DataType>::DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

/**
 * @brief Destructor - Clears all nodes from memory.
 */
template <typename DataType>
DoublyLinkedList<DataType>::~DoublyLinkedList() {
    clear();
}

/**
 * @brief Copy Constructor - Creates a deep copy of the list.
 */
template <typename DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), length(0) {
    Node* current = other.head;
    while (current) {
        insertBack(current->data);
        current = current->next;
    }
}

/**
 * @brief Assignment Operator
 */
template <typename DataType>
DoublyLinkedList<DataType>& DoublyLinkedList<DataType>::operator=(const DoublyLinkedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            insertBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

/**
 * @brief Inserts a value at the front of the list.
 */
template <typename DataType>
void DoublyLinkedList<DataType>::insertFront(const DataType& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    ++length;
}


/**
 * @brief Inserts a value at the back of the list.
 */
template <typename DataType>
void DoublyLinkedList<DataType>::insertBack(const DataType& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++length;
}

/**
 * @brief Deletes the first occurrence of the specified value.
 */
template <typename DataType>
bool DoublyLinkedList<DataType>::deleteItem(const DataType& value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;
            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;
            delete current;
            --length;
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
 * @brief Checks if the list is empty.
 */
template <typename DataType>
bool DoublyLinkedList<DataType>::isEmpty() const {
    return length == 0;
}

/**
 * @brief Clears the list and deallocates all nodes.
 */
template <typename DataType>
void DoublyLinkedList<DataType>::clear() {
    while (!isEmpty()) {
        deleteItem(head->data);
    }
}

/**
 * @brief Returns the number of elements in the list.
 */
template <typename DataType>
int DoublyLinkedList<DataType>::getLength() const {
    return length;
}

/**
 * @brief Begin - Points to the first node.
 */
template <typename DataType>
typename DoublyLinkedList<DataType>::Iterator DoublyLinkedList<DataType>::begin() const {
    return Iterator(head, tail);
}

/**
 * @brief End - Points to nullptr.
 */
template <typename DataType>
typename DoublyLinkedList<DataType>::Iterator DoublyLinkedList<DataType>::end() const {
    return Iterator(nullptr, tail);
}

/**
 * @brief Overload << operator for printing the list.
 */
template <typename DataType>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<DataType>& list) {
    typename DoublyLinkedList<DataType>::Node* current = list.head;
    os << "[";
    while (current) {
        os << current->data;
        if (current->next) os << ", ";
        current = current->next;
    }
    os << "]";
    return os;
}

