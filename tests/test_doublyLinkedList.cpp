#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include "../DoublyLinkedList.h"

TEST_CASE("DoublyLinkedList: Basic Operations with Integers") {
    SECTION("InsertFront and InsertBack with Integers") {
        DoublyLinkedList<int> list;
        list.insertFront(10);
        list.insertBack(20);
        list.insertFront(5);

        REQUIRE(list.getLength() == 3);
        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[5, 10, 20]");
    }

    SECTION("DeleteItem with Integers") {
        DoublyLinkedList<int> list;
        list.insertBack(10);
        list.insertBack(20);
        list.insertBack(30);

        REQUIRE(list.deleteItem(20));
        REQUIRE(list.getLength() == 2);

        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[10, 30]");

        REQUIRE(!list.deleteItem(40)); // Element not in list
    }

    SECTION("Clear with Integers") {
        DoublyLinkedList<int> list;
        list.insertBack(10);
        list.insertBack(20);
        list.insertBack(30);

        list.clear();
        REQUIRE(list.isEmpty());
        REQUIRE(list.getLength() == 0);

        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[]");
    }

    SECTION("IsEmpty with Integers") {
        DoublyLinkedList<int> list;
        REQUIRE(list.isEmpty());

        list.insertBack(10);
        REQUIRE_FALSE(list.isEmpty());
    }

    SECTION("Copy Constructor with Integers") {
        DoublyLinkedList<int> originalList;
        originalList.insertBack(10);
        originalList.insertBack(20);
        originalList.insertBack(30);

        DoublyLinkedList<int> copiedList = originalList;
        REQUIRE(copiedList.getLength() == originalList.getLength());

        std::ostringstream outputOriginal, outputCopied;
        outputOriginal << originalList;
        outputCopied << copiedList;
        REQUIRE(outputOriginal.str() == outputCopied.str());
    }

    SECTION("Assignment Operator with Integers") {
        DoublyLinkedList<int> list1;
        list1.insertBack(10);
        list1.insertBack(20);

        DoublyLinkedList<int> list2;
        list2 = list1;

        REQUIRE(list2.getLength() == list1.getLength());

        std::ostringstream output1, output2;
        output1 << list1;
        output2 << list2;
        REQUIRE(output1.str() == output2.str());
    }
}

TEST_CASE("DoublyLinkedList: Basic Operations with Strings") {
    SECTION("InsertFront and InsertBack with Strings") {
        DoublyLinkedList<std::string> list;
        list.insertFront("Apple");
        list.insertBack("Banana");
        list.insertFront("Cherry");

        REQUIRE(list.getLength() == 3);
        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[Cherry, Apple, Banana]");
    }

    SECTION("DeleteItem with Strings") {
        DoublyLinkedList<std::string> list;
        list.insertBack("Apple");
        list.insertBack("Banana");
        list.insertBack("Cherry");

        REQUIRE(list.deleteItem("Banana"));
        REQUIRE(list.getLength() == 2);

        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[Apple, Cherry]");

        REQUIRE(!list.deleteItem("Date")); // Element not in list
    }

    SECTION("Clear with Strings") {
        DoublyLinkedList<std::string> list;
        list.insertBack("Apple");
        list.insertBack("Banana");
        list.insertBack("Cherry");

        list.clear();
        REQUIRE(list.isEmpty());
        REQUIRE(list.getLength() == 0);

        std::ostringstream output;
        output << list;
        REQUIRE(output.str() == "[]");
    }

    SECTION("IsEmpty with Strings") {
        DoublyLinkedList<std::string> list;
        REQUIRE(list.isEmpty());

        list.insertBack("Apple");
        REQUIRE_FALSE(list.isEmpty());
    }

    SECTION("Copy Constructor with Strings") {
        DoublyLinkedList<std::string> originalList;
        originalList.insertBack("Apple");
        originalList.insertBack("Banana");
        originalList.insertBack("Cherry");

        DoublyLinkedList<std::string> copiedList = originalList;
        REQUIRE(copiedList.getLength() == originalList.getLength());

        std::ostringstream outputOriginal, outputCopied;
        outputOriginal << originalList;
        outputCopied << copiedList;
        REQUIRE(outputOriginal.str() == outputCopied.str());
    }

    SECTION("Assignment Operator with Strings") {
        DoublyLinkedList<std::string> list1;
        list1.insertBack("Apple");
        list1.insertBack("Banana");

        DoublyLinkedList<std::string> list2;
        list2 = list1;

        REQUIRE(list2.getLength() == list1.getLength());

        std::ostringstream output1, output2;
        output1 << list1;
        output2 << list2;
        REQUIRE(output1.str() == output2.str());
    }
}
