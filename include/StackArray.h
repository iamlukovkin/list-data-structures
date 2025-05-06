#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#pragma once
#include <iostream>
#include "Stack.h"
#include <stdexcept>

template<typename DataType>
class StackArray final : public Stack<DataType> {
    DataType *stackValues;
    int capacity;
    int countInStack;

    void resize(const int newCapacity) {
        auto *newStackValues = new DataType[newCapacity];
        for (int i = 0; i < countInStack; i++) {
            newStackValues[i] = stackValues[i];
        }
        delete[] stackValues;
        stackValues = newStackValues;
        capacity = newCapacity;
    }

public:
    StackArray() : stackValues(nullptr), capacity(0), countInStack(0) {
    }

    ~StackArray() override {
        delete[] stackValues;
    }

    void push(DataType x) override {
        if (countInStack == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = countInStack; i > 0; --i) {
            stackValues[i] = stackValues[i - 1];
        }
        stackValues[0] = x;
        countInStack++;
    }

    DataType ret() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty.");
        }
        return stackValues[0];
    }

    DataType pop() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty.");
        }
        DataType element = stackValues[0];
        for (int i = 1; i < countInStack; ++i) {
            stackValues[i - 1] = stackValues[i];
        }
        countInStack--;
        if (countInStack < capacity / 4) {
            resize(capacity / 2);
        }

        return element;
    }

    bool isEmpty() override {
        return countInStack == 0;
    }
};

#endif // STACK_ARRAY_H
