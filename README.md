![Points bar](../../blob/badges/.github/badges/points-bar.svg)
# Lab Assignment: Templated Doubly Linked List in C++

## Overview

In this lab, you will implement a doubly linked list class that is templated to hold values of any datatype. You will also create an iterator subclass to traverse the list in both forward and reverse directions. This assignment strengthens your understanding of class templates, dynamic memory management, operator overloading, and iterator functionality in C++.

### Concepts Covered
- Templated classes
- Doubly linked list structure and operations
- Dynamic memory management
- Iterators for forward and reverse traversal
- Operator overloading

---

## Lab Objectives

By completing this lab, you will:
1. Implement a templated doubly linked list in C++.
2. Create an iterator subclass for bidirectional traversal of the list.
3. Handle edge cases like decrementing an iterator from `end()`.
4. Understand and adhere to the C++ Standard Library conventions for `begin()` and `end()` iterators.
5. Practice exception handling and dynamic memory safety.

---
**Grading rubric (100 points possible (60 autograded))**

| Points | Requirements                                            |
|-------|---------------------------------------------------------|
| 30    | DoublyLinkedList Methods  (Autograded)                  |
| 30    | Iterator Methods  (Autograded)                          |
| 10    | Driver                                                  |
| 30    | Good coding practices. (Including Documenting comments) |

---
## Instructions

### Core Requirements

### **Part 1: Doubly Linked List Implementation**

1. **Declare a Class Template:**
    - Define a template class `DoublyLinkedList<DataType>` where `DataType` represents the type of data stored in the list.

2. **Core Methods:**
    - Implement the following member functions:
        - `void insertFront(const DataType& value);`
            - Add an item to the front of the list.
        - `void insertBack(const DataType& value);`
            - Add an item to the back of the list.
        - `bool deleteItem(const DataType& value);`
            - Remove the first occurrence of an item matching the value.
        - `bool isEmpty() const;`
            - Check if the list is empty.
        - `void clear();`
            - Remove all items from the list.
        - `int getLength() const;`
            - Return the number of nodes in the list.

3. **Rule of Three:**
    - Implement the following special member functions to handle dynamic memory safely:
        - Destructor: Ensure all dynamically allocated nodes are deallocated.
        - Copy constructor: Create a deep copy of another `DoublyLinkedList`.
        - Assignment operator: Allow one `DoublyLinkedList` to be assigned to another.

### **Part 2: Iterator Subclass**

1. **Define a Nested Iterator Class:**
    - Create a nested `Iterator` subclass within `DoublyLinkedList` to support bidirectional traversal.

2. **Iterator Operations:**
    - Implement the following:
        - `DataType& operator*();`
            - Dereference the iterator to access the current node's data.
        - `Iterator& operator++();`
            - Move the iterator forward to the next node.
        - `Iterator& operator--();`
            - Move the iterator backward to the previous node.
            - **Note:** Decrementing an `end()` iterator dynamically accesses the list's `tail` pointer.  There are a few ways to accomplish this 1) is to have the iterator contain a pointer to the DoublyListList, or 2) it can contain a pointer to the tail pointer.  
              - If the iterator cannot decrement (e.g., an empty list), it throws a `std::logic_error` exception.
        - `bool operator==(const Iterator& other) const;`
            - Compare two iterators for equality.
        - `bool operator!=(const Iterator& other) const;`
            - Compare two iterators for inequality.

3. **Adhere to C++ Iterator Conventions:**
    - `begin()` returns an iterator pointing to the first node.
    - `end()` returns an iterator pointing to `nullptr` (one past the last node).

4. **Exception Handling:**
    - Ensure `operator--` throws a meaningful exception when called on an invalid state (e.g., `end()` for an empty list).

### **Part 3: Overloaded Operators**

1. **Output Operator (`<<`)**:
    - Overload the `<<` operator to print the list in the format:
      ```
      [value1, value2, ..., valueN]
      ```

---

## Example Usage

```cpp
#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    std::cout << "List contents: " << list << std::endl;
    std::cout << "List size: " << list.getLength() << std::endl;

    DoublyLinkedList<int>::Iterator it = list.begin();
    std::cout << "First element: " << *it << std::endl;

    ++it;
    std::cout << "Second element: " << *it << std::endl;

    --it;
    std::cout << "Back to first element: " << *it << std::endl;

    return 0;
}
```

---

## Testing

1. **Your Driver**
    You're driver should demonstrate all the features of the DoublyLinkedList class including iterator methods. 

2. **Doubly Linked List Tests:**
    These tests will test all the methods of the DoublyLinkedList. 

3. **Iterator Tests:**
    these tests will tests the features of the Iterators

---

## Submission

To turn in the assignment make sure to commit and push your code to the GitHub Repository and then copy the link to the Canvas assignment and submit. 

### Notes:
- Ensure your code follows clean coding standards with proper comments.
- Include Doxygen-style comments for all methods and classes.

---

**Reminder:** Adhering to C++ Standard Library conventions is crucial for writing robust, maintainable code. Ensure your iterators behave like standard library iterators, and all dynamic memory is managed safely.

