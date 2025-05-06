# ListDataStructures

A C++ project implementing various data structures and evaluating prefix and postfix expressions using a stack-based
approach. This project includes linked list operations, stack implementations, and evaluates mathematical expressions in
both prefix and postfix notation.

## Features

- **Linked list Implementations (`LinkedList`)**:
-
- **Stack Implementations**:
    - Stack implemented using an array (`StackArray`).
    - Stack implemented using a linked list (`StackList`).

- **Expression Evaluation**:
    - Prefix Expression Evaluator (`PrefixEvaluator`).
    - Postfix Expression Evaluator (`PostfixEvaluator`).

- **Testing**:
    - Unit tests for linked list operations.
    - Unit tests for stack operations.
    - Unit tests for prefix and postfix expression evaluation.

## Project Structure

```
.
├── CMakeLists.txt
├── main.cpp 
├── src/
│ ├── TestPrefixEvaluator.cpp
│ ├── TestPostfixEvaluator.cpp
│ ├── TestStack.cpp
│ ├── TestLinkedList.cpp
├── include/
│ ├── Color.h
│ ├── LinkedList.h
│ ├── PostfixEvaluator.h
│ ├── PrefixEvaluator.h
│ ├── Stack.h
│ ├── StackArray.h
│ └── StackList.h
├── errors/
│ ├── PostfixEvaluatorErrors.h
│ └── PrefixEvaluatorErrors.h
└── tests/
├── LinkedListTest.h
├── PostfixEvaluatorTest.h
├── PrefixEvaluatorTest.h
└── StackTest.h
```

## Requirements

- C++20 compatible compiler.
- CMake (version 3.31 or later).
