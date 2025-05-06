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

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/iamlukovkin/list-data-structures.git
    cd ListDataStructures
    ```

2. Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:

    ```bash
    cmake ..
   ```

4. Build a project:

    ```bash
    cmake --build .
   ```

5. Run the executable:

    ```bash
    ./ListDataStructires
    ```

## Usage

This project evaluates mathematical expressions in both prefix and postfix notation using the stack data structure. You can add more expressions in the test cases, or you can modify main.cpp to add your own logic for expression evaluation.

## Tests

The project includes unit tests for:

- Linked List Operations: Insertions, deletions, traversal.
- Stack Operations: Push, pop, top, and checking if the stack is empty.
- Expression Evaluators: Evaluates both prefix and postfix expressions and tests for edge cases like division by zero or invalid operators.

To run the tests:

- Modify the main.cpp file to call the respective test functions.
- Rebuild the project using `cmake --build ..`

Made with ❤️ by [iamlukovkin](https://github.com/iamlukovkin)

### Explanation:
- **Project Overview**: The introduction explains the general purpose of the project, the core functionalities, and features.
- **Project Structure**: Lists the file and directory structure of the project to give users an understanding of how the project is organized.
- **Requirements**: Specifies the requirements for building the project, including the compiler and CMake version.
- **Installation**: Step-by-step instructions on how to clone, configure, build, and run the project.
- **Usage**: Describes how users can utilize the project for evaluating expressions or extend it.
- **Tests**: Mentions the available tests and how to execute them.

Feel free to modify or expand this based on additional details specific to your project.