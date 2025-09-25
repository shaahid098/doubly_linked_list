#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <sstream>
#include "../DoublyLinkedList.h"


TEST_CASE("DoublyLinkedList Iterator: Basic Operations with Integers") {
    DoublyLinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    SECTION("Dereference Operator with Integers") {
        auto it = list.begin();
        REQUIRE(*it == 10);
    }

    SECTION("Pre-increment Operator with Integers") {
        auto it = list.begin();
        ++it;
        REQUIRE(*it == 20);
        ++it;
        REQUIRE(*it == 30);
    }

    SECTION("Pre-decrement Operator with Integers") {
        auto it = list.end();
        --it; // Should move to the last element
        REQUIRE(*it == 30);
        --it; // Should move to the second-to-last element
        REQUIRE(*it == 20);
    }

    SECTION("Decrementing from end() with Integers") {
        auto it = list.end();
        --it; // Moves to the last element
        REQUIRE(*it == 30);
    }

    SECTION("Equality and Inequality Operators with Integers") {
        auto it1 = list.begin();
        auto it2 = list.begin();
        REQUIRE(it1 == it2);
        ++it1;
        REQUIRE(it1 != it2);
    }

    SECTION("Iteration through the List with Integers") {
        std::ostringstream output;
        for (auto it = list.begin(); it != list.end(); ++it) {
            output << *it << " ";
        }
        REQUIRE(output.str() == "10 20 30 ");
    }

    SECTION("Reverse Iteration through the List with Integers") {
        std::ostringstream output;
        auto it = list.end();
        while (it != list.begin()) {
            --it;
            output << *it << " ";
        }
        REQUIRE(output.str() == "30 20 10 ");
    }
}

TEST_CASE("DoublyLinkedList Iterator: Basic Operations with Strings") {
    DoublyLinkedList<std::string> list;
    list.insertBack("Apple");
    list.insertBack("Banana");
    list.insertBack("Cherry");

    SECTION("Dereference Operator with Strings") {
        auto it = list.begin();
        REQUIRE(*it == "Apple");
    }

    SECTION("Pre-increment Operator with Strings") {
        auto it = list.begin();
        ++it;
        REQUIRE(*it == "Banana");
        ++it;
        REQUIRE(*it == "Cherry");
    }

    SECTION("Pre-decrement Operator with Strings") {
        auto it = list.end();
        --it; // Should move to the last element
        REQUIRE(*it == "Cherry");
        --it; // Should move to the second-to-last element
        REQUIRE(*it == "Banana");
    }

    SECTION("Decrementing from end() with Strings") {
        auto it = list.end();
        --it; // Moves to the last element
        REQUIRE(*it == "Cherry");
    }

    SECTION("Equality and Inequality Operators with Strings") {
        auto it1 = list.begin();
        auto it2 = list.begin();
        REQUIRE(it1 == it2);
        ++it1;
        REQUIRE(it1 != it2);
    }

    SECTION("Iteration through the List with Strings") {
        std::ostringstream output;
        for (auto it = list.begin(); it != list.end(); ++it) {
            output << *it << " ";
        }
        REQUIRE(output.str() == "Apple Banana Cherry ");
    }

    SECTION("Reverse Iteration through the List with Strings") {
        std::ostringstream output;
        auto it = list.end();
        while (it != list.begin()) {
            --it;
            output << *it << " ";
        }
        REQUIRE(output.str() == "Cherry Banana Apple ");
    }
}
