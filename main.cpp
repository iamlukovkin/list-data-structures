#include <iostream>
#include <memory>
#include "errors/PostfixEvaluatorErrors.h"

#include "include/Color.h"
#include "include/PrefixEvaluator.h"
#include "include/StackArray.h"
#include "include/StackList.h"
#include "tests/LinkedListTest.h"
#include "tests/PostfixEvaluatorTest.h"

#include "tests/StackTest.h"

using namespace std;

void postfixEvaluatorTest() {
    using namespace PostfixEvaluatorErrors;
    const vector<PostfixTestCase> testCases = {
        {"3 4 +", 7, ""},
        {"10 3 -", 7, ""},
        {"2 5 *", 10, ""},
        {"8 2 /", 4, ""},
        {"3 2 2 * +", 7, ""},
        {"1 2 + 3 4 + *", 21, ""},
        {"10 5 * 15 -", 35, ""},
        {"2 3 * 8 2 / +", 10, ""},
        {"6 2 + 9 3 - /", 1, ""},
        {"1 2 + 3 4 +  +", 10, ""},
        {"3", 3, ""},
        {"10 0 /", std::nullopt, ERR_DIVISION_BY_ZERO},
        {"3 +", std::nullopt, ERR_NOT_ENOUGH_OPERANDS},
        {"3 4 @", std::nullopt, string(ERR_INVALID_TOKEN_PREFIX) + "@"},
        {"3 4 + 5", std::nullopt, ERR_LEFTOVER_OPERANDS}
    };

    cout << BOLD << CYAN << "--- Testing with StackArray ---" << endl;
    const auto stackArray = make_unique<StackArray<int> >();
    const PostfixEvaluatorTest testArray(stackArray.get());
    testArray.run(testCases);

    cout << BOLD << CYAN << "--- Testing with StackList ---" << endl;
    const auto stackList = make_unique<StackList<int> >();
    const PostfixEvaluatorTest testList(stackList.get());
    testList.run(testCases);
}


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
    postfixEvaluatorTest();
    return 0;
}
