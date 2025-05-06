#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include <sstream>
#include <string>
#include <stdexcept>
#include "../include/Stack.h"

using namespace std;

class PostfixEvaluator {
    Stack<int> *stack;

    static constexpr auto ERR_NOT_ENOUGH_OPERANDS = "Invalid expression: not enough operands for the operator.";
    static constexpr auto ERR_DIVISION_BY_ZERO = "Division by zero error.";
    static constexpr auto ERR_INVALID_TOKEN = "Invalid token: ";
    static constexpr auto ERR_STACK_EMPTY = "Invalid expression: stack is empty after evaluation.";
    static constexpr auto ERR_LEFTOVER_OPERANDS = "Invalid expression: leftover operands in stack.";

public:
    explicit PostfixEvaluator(Stack<int> *stackImpl) : stack(stackImpl) {
    }

    [[nodiscard]] int evaluate(const string &expression) const {
        stringstream ss(expression);
        string token;

        while (ss >> token) {
            if (isdigit(token[0]) || (token.size() > 1 && (token[0] == '-' || token[0] == '+') && isdigit(token[1]))) {
                stack->push(stoi(token));
            } else if (isOperator(token)) {
                if (stack->isEmpty()) {
                    throw runtime_error(ERR_NOT_ENOUGH_OPERANDS);
                }
                const int secondOperand = stack->pop();

                if (stack->isEmpty()) {
                    throw runtime_error(ERR_NOT_ENOUGH_OPERANDS);
                }
                const int firstOperand = stack->pop();

                const int result = performOperation(token, firstOperand, secondOperand);
                stack->push(result);
            } else {
                throw runtime_error(ERR_INVALID_TOKEN + token);
            }
        }

        if (stack->isEmpty()) {
            throw runtime_error(ERR_STACK_EMPTY);
        }

        const int result = stack->pop();

        if (!stack->isEmpty()) {
            throw runtime_error(ERR_LEFTOVER_OPERANDS);
        }

        return result;
    }

private:
    static bool isOperator(const string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    static int performOperation(const string &op, const int operand1, const int operand2) {
        if (op == "+") return operand1 + operand2;
        if (op == "-") return operand1 - operand2;
        if (op == "*") return operand1 * operand2;
        if (op == "/") {
            if (operand2 == 0) throw runtime_error(ERR_DIVISION_BY_ZERO);
            return operand1 / operand2;
        }
        throw runtime_error("Unknown operator: " + op);
    }
};

#endif // POSTFIX_EVALUATOR_H
