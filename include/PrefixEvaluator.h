#ifndef PREFIX_EVALUATOR_H
#define PREFIX_EVALUATOR_H

#include <sstream>
#include <string>
#include <stdexcept>
#include "../include/Stack.h"

using namespace std;

class PrefixEvaluator {
    Stack<int>* stack;

public:
    explicit PrefixEvaluator(Stack<int>* stackImpl) : stack(stackImpl) {}

    [[nodiscard]] int evaluate(const string& expression) const {
        vector<string> tokens;
        stringstream ss(expression);
        string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
            token = *it;

            if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
                stack->push(stoi(token));
            } else if (isOperator(token)) {
                if (stack->isEmpty()) {
                    throw runtime_error("Invalid expression: not enough operands for the operator.");
                }
                const int firstOperand = stack->pop();
                if (stack->isEmpty()) {
                    throw runtime_error("Invalid expression: not enough operands for the operator.");
                }
                const int secondOperand = stack->pop();
                const int result = performOperation(token, firstOperand, secondOperand);
                stack->push(result);
            } else {
                throw runtime_error("Invalid token: " + token);
            }
        }
        if (stack->isEmpty()) {
            throw runtime_error("Invalid expression: stack is empty after evaluation.");
        }
        const int result = stack->pop();
        if (!stack->isEmpty()) {
            throw runtime_error("Invalid expression: leftover operands in stack.");
        }
        return result;
    }




private:
    static bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    static int performOperation(const string& op, const int operand1, const int operand2) {
        if (op == "+") return operand1 + operand2;
        if (op == "-") return operand1 - operand2;
        if (op == "*") return operand1 * operand2;
        if (op == "/") {
            if (operand2 == 0) throw runtime_error("Division by zero error.");
            return operand1 / operand2;
        }
        throw runtime_error("Unknown operator: " + op);
    }
};

#endif // PREFIX_EVALUATOR_H
