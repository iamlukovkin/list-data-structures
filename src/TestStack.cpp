#include "TestStack.h"

#include "../include/StackArray.h"
#include "../include/StackList.h"
#include "../tests/StackTest.h"

void testStack() {
    const StackTest stackArrayTest(std::make_unique<StackArray<int> >());
    stackArrayTest.runTests();
    const StackTest stackListTest(std::make_unique<StackList<int> >());
    stackListTest.runTests();
}
