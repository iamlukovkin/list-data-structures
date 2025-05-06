#ifndef STACK_TEST_H
#define STACK_TEST_H

#include <iostream>
#include <cassert>

#include "../include/Stack.h"
#include "../include/Color.h"

class StackTest {
    std::unique_ptr<Stack<int>> stack;

public:
    explicit StackTest(std::unique_ptr<Stack<int>> stackImpl) : stack(std::move(stackImpl)) {}

    void testPush() const {
        stack->push(5);
        stack->push(6);
        stack->push(7);
        std::cout << GREEN << "[PASSED] " << RESET << "testPush | Pushed elements: 5, 6, 7\n";
    }

    void testRet() const {
        int topElement = stack->ret();
        assert(topElement == 7);
        std::cout << GREEN << "[PASSED] " << RESET << "testRet | Top element: " << topElement << "\n";
    }

    void testPop() const {
        int poppedElement = stack->pop();
        assert(poppedElement == 7);
        std::cout << GREEN << "[PASSED] " << RESET << "testPop | Popped element: " << poppedElement << "\n";
    }

    void testIsEmpty() const {
        stack->pop();
        stack->pop();
        bool empty = stack->isEmpty();
        assert(empty);
        std::cout << GREEN << "[PASSED] " << RESET << "testIsEmpty | Stack is empty: Yes\n";
    }

    void runTests() const {
        std::cout << BOLD << CYAN << "--- Testing Stack ---\n" << RESET;
        testPush();
        testRet();
        testPop();
        testIsEmpty();
    }
};

#endif // STACK_TEST_H
