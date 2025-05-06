#ifndef PREFIX_EVALUATOR_TEST_H
#define PREFIX_EVALUATOR_TEST_H

#include <vector>
#include <string>
#include <iostream>
#include <optional>
#include "../include/Stack.h"
#include "../include/Color.h"
#include "../include/PrefixEvaluator.h"

using namespace std;

struct PrefixTestCase {
    std::string expression;
    std::optional<int> expectedResult;
    std::string expectedError;
};

class PrefixEvaluatorTest {
    Stack<int> *stack;

public:
    explicit PrefixEvaluatorTest(Stack<int> *stackImpl) : stack(stackImpl) {
    }

    void run(const vector<PrefixTestCase> &testCases) const {
        const PrefixEvaluator evaluator(stack);
        int passed = 0;
        const int total = static_cast<int>(testCases.size());
        cout << BOLD << CYAN << "\n--- Testing PrefixEvaluator ---\n" << RESET;
        for (const auto &test: testCases) {
            cout << BOLD << YELLOW << "\nRunning Test: " << RESET << test.expression << endl;
            cout << BOLD << GREEN << "Expected result: " << (test.expectedResult.has_value()
                                                                 ? to_string(test.expectedResult.value())
                                                                 : "N/A") << RESET << endl;
            try {
                int result = evaluator.evaluate(test.expression);
                if (test.expectedResult.has_value() && result == test.expectedResult.value()) {
                    cout << GREEN << "[PASSED] " << RESET << test.expression
                            << " = " << result << endl;
                    ++passed;
                } else {
                    cout << RED << "[FAILED] " << RESET << test.expression
                            << " | Expected: " << test.expectedResult.value_or(-999)
                            << ", Got: " << result << endl;
                }
            } catch (const exception &e) {
                if (!test.expectedResult.has_value() && test.expectedError == e.what()) {
                    cout << GREEN << "[PASSED] " << RESET << test.expression
                            << " threw expected error: " << e.what() << endl;
                    ++passed;
                } else {
                    cout << RED << "[FAILED] " << RESET << test.expression
                            << " | Unexpected error: " << e.what()
                            << " | Expected error: " << test.expectedError << endl;
                }
            }
            while (!stack->isEmpty()) {
                stack->pop();
            }
        }
        if (passed == total) {
            cout << GREEN << "\nTest summary: " << passed << " / " << total << " tests passed." << RESET << endl;
        } else {
            cout << RED << "\nTest summary: " << passed << " / " << total << " tests passed." << RESET << endl;
        }
    }
};

#endif // PREFIX_EVALUATOR_TEST_H
