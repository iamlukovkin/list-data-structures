cmake_minimum_required(VERSION 3.31)
project(ListDataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListDataStructures main.cpp
        src/TestPrefixEvaluator.cpp
        src/TestPostfixEvaluator.cpp
        src/TestStack.cpp
        src/TestLinkedList.cpp)

target_include_directories(ListDataStructures PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/errors
        ${CMAKE_SOURCE_DIR}/tests
        ${CMAKE_SOURCE_DIR}/src
)

