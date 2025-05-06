#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <sstream>

template<typename DataType>
class LinkedList {
public:
    struct Node {
        DataType data;
        Node *next;

        explicit Node(const DataType &value = DataType(), Node *nextPtr = nullptr)
            : data(value), next(nextPtr) {
        }
    };

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        clear();
    }

    void insert(const DataType &value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    static DataType returnData(Node *p) {
        return (p != nullptr) ? p->data : DataType();
    }

    Node *locate(const DataType &value) const {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static Node *next(Node *p) {
        return (p != nullptr) ? p->next : nullptr;
    }

    Node *prev(Node *p) const {
        if (head == nullptr || p == head) return nullptr;

        Node *current = head;
        while (current->next != nullptr && current->next != p) {
            current = current->next;
        }
        return (current->next == p) ? current : nullptr;
    }

    Node *first() const {
        return head;
    }

    Node *last() const {
        if (head == nullptr) return nullptr;

        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    void deleteNext(Node *p) {
        if (p == nullptr || p->next == nullptr) return;

        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }

    [[nodiscard]] std::string toString() const {
        std::ostringstream oss;
        oss << "[";
        Node *current = head;
        bool firstElem = true;
        while (current != nullptr) {
            if (!firstElem) oss << ", ";
            oss << current->data;
            firstElem = false;
            current = current->next;
        }
        oss << "]";
        return oss.str();
    }

    void clear() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

private:
    Node *head;
};

#endif
