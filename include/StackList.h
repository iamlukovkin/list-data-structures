#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H

#include "Stack.h"
#include <stdexcept>

template<typename DataType>
class StackList final : public Stack<DataType> {
    struct Node {
        DataType data;
        Node *next;

        explicit Node(const DataType &value = DataType(), Node *nextPtr = nullptr)
            : data(value), next(nextPtr) {
        }
    };

    Node *head;

public:
    StackList() {
        head = new Node();
    }

    ~StackList() override {
        clear();
        delete head;
    }

    void push(DataType value) override {
        Node *newNode = new Node(value, head->next);
        head->next = newNode;
    }

    DataType ret() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return head->next->data;
    }

    DataType pop() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        Node *top = head->next;
        DataType value = top->data;
        head->next = top->next;
        delete top;
        return value;
    }

    bool isEmpty() override {
        return head->next == nullptr;
    }

private:
    void clear() {
        Node *current = head->next;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head->next = nullptr;
    }
};

#endif // STACK_BY_LIST_H
