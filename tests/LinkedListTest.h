#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

#include <iostream>
#include <string>
#include "../include/LinkedList.h"
#include "../include/Color.h"

using namespace std;

struct LinkedListTestCase {
    std::string testName;
    std::string operation;
    std::optional<std::string> expectedResult;
    std::string expectedError;
};

class LinkedListTest {
    static void testInsert() {
        LinkedList<int> list;
        list.insert(5);
        list.insert(10);
        list.insert(15);
        string result = list.toString();
        if (result == "[5, 10, 15]") {
            cout << GREEN << "[PASSED] " << RESET << "insert | Expected: [5, 10, 15] | Got: " << result << endl;
        } else {
            cout << RED << "[FAILED] " << RESET << "insert | Expected: [5, 10, 15] | Got: " << result << endl;
        }
    }

    static void testLocate() {
        LinkedList<int> list;
        list.insert(5);
        list.insert(10);
        list.insert(15);
        LinkedList<int>::Node* node = list.locate(10);
        if (LinkedList<int>::returnData(node) == 10) {
            cout << GREEN << "[PASSED] " << RESET << "locate | Expected result: 10 | Got: " << LinkedList<int>::returnData(node) << endl;
        } else {
            cout << RED << "[FAILED] " << RESET << "locate | Expected: 10 | Got: " << LinkedList<int>::returnData(node) << endl;
        }
    }

    static void testDeleteNext() {
        LinkedList<int> list;
        list.insert(5);
        list.insert(10);
        list.insert(15);

        LinkedList<int>::Node* nodeBefore10 = list.locate(5);
        list.deleteNext(nodeBefore10);

        const string expected = "[5, 15]";

        if (const string got = list.toString(); expected == got) {
            cout << GREEN << "[PASSED] " << RESET << "deleteNext | Expected: " << expected << " | Got: " << got << endl;
        } else {
            cout << RED << "[FAILED] " << RESET << "deleteNext | Expected: " << expected << " | Got: " << got << endl;
        }
    }

    static void testFirst() {
        LinkedList<int> list;
        list.insert(5);
        list.insert(10);
        list.insert(15);
        LinkedList<int>::Node* node = list.first();
        if (LinkedList<int>::returnData(node) == 5) {
            cout << GREEN << "[PASSED] " << RESET << "first | Expected result: 5 | Got: " << LinkedList<int>::returnData(node) << endl;
        } else {
            cout << RED << "[FAILED] " << RESET << "first | Expected: 5 | Got: " << LinkedList<int>::returnData(node) << endl;
        }
    }

    static void testLast() {
        LinkedList<int> list;
        list.insert(5);
        list.insert(10);
        list.insert(15);
        LinkedList<int>::Node* node = list.last();
        if (LinkedList<int>::returnData(node) == 15) {
            cout << GREEN << "[PASSED] " << RESET << "last | Expected result: 15 | Got: " << LinkedList<int>::returnData(node) << endl;
        } else {
            cout << RED << "[FAILED] " << RESET << "last | Expected: 15 | Got: " << LinkedList<int>::returnData(node) << endl;
        }
    }

public:
    static void run() {
        cout << BOLD << CYAN << "\n--- Testing LinkedList ---\n" << RESET;
        testInsert();
        testLocate();
        testDeleteNext();
        testFirst();
        testLast();
    }
};

#endif
