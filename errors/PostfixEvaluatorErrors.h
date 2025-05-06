#ifndef POSTFIX_EVALUATOR_ERRORS_H
#define POSTFIX_EVALUATOR_ERRORS_H

namespace PostfixEvaluatorErrors {
    constexpr auto ERR_NOT_ENOUGH_OPERANDS = "Invalid expression: not enough operands for the operator.";
    constexpr auto ERR_DIVISION_BY_ZERO = "Division by zero error.";
    constexpr auto ERR_INVALID_TOKEN_PREFIX = "Invalid token: ";
    constexpr auto ERR_STACK_EMPTY = "Invalid expression: stack is empty after evaluation.";
    constexpr auto ERR_LEFTOVER_OPERANDS = "Invalid expression: leftover operands in stack.";
}

#endif // POSTFIX_EVALUATOR_ERRORS_H
