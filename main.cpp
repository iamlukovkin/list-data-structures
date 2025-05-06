#include "tests/StackTest.h"
#include "include/StackArray.h"
#include "include/StackList.h"
#include "tests/LinkedListTest.h"

void linkedListTest() {
    LinkedListTest::run();
}

void stacksTest() {
    const StackTest stackArrayTest(std::make_unique<StackArray<int> >());
    stackArrayTest.runTests();
    const StackTest stackListTest(std::make_unique<StackList<int> >());
    stackListTest.runTests();
}

int main() {
    linkedListTest();
    stacksTest();
    return 0;
}