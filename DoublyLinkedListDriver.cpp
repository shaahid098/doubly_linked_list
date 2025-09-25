#include <iostream>
#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    std::cout << "List contents: " << list << std::endl;
    std::cout << "List size: " << list.getLength() << std::endl;

    auto it = list.begin();
    std::cout << "First element: " << *it << std::endl;

    ++it;
    std::cout << "Second element: " << *it << std::endl;

    --it;
    std::cout << "Back to first element: " << *it << std::endl;

    return 0;
}
