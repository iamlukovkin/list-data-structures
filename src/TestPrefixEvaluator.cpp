#include "TestPrefixEvaluator.h"

#include "../errors/PrefixEvaluatorErrors.h"
#include "../tests/PrefixEvaluatorTest.h"
#include "../include/StackArray.h"
#include "../include/StackList.h"

using namespace std;

void testPrefixEvaluator() {
    using namespace PrefixEvaluatorErrors;
    const vector<PrefixTestCase> testCases = {
        {"+ 3 4", 7, ""},
        {"- 10 3", 7, ""},
        {"* 2 5", 10, ""},
        {"/ 8 2", 4, ""},
        {"+ 3 * 2 2", 7, ""},
        {"* + 1 2 + 3 4", 21, ""},
        {"- * 10 5 15", 35, ""},
        {"+ * 2 3 / 8 2", 10, ""},
        {"/ + 6 2 - 9 3", 1, ""},
        {"+ + + 1 2 3 4", 10, ""},
        {"+ 3", std::nullopt, ERR_NOT_ENOUGH_OPERANDS},
        {"/ 10 0", std::nullopt, ERR_DIVISION_BY_ZERO},
        {"* + 3", std::nullopt, ERR_NOT_ENOUGH_OPERANDS},
        {"@ 3 4", std::nullopt, string(ERR_INVALID_TOKEN_PREFIX) + "@"},
        {"+ 3 4 5", std::nullopt, ERR_LEFTOVER_OPERANDS}
    };

    cout << "--- Testing with StackArray ---" << endl;
    const auto stackArray = make_unique<StackArray<int> >();
    const PrefixEvaluatorTest testArray(stackArray.get());
    testArray.run(testCases);

    cout << "--- Testing with StackList ---" << endl;
    auto stackList = make_unique<StackList<int> >();
    const PrefixEvaluatorTest testList(stackList.get());
    testList.run(testCases);
}
