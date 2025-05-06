#ifndef STACK_H
#define STACK_H

template<typename DataType>
class Stack {
public:
    virtual ~Stack() = default;

    virtual void push(DataType value) = 0;

    virtual DataType ret() = 0;

    virtual DataType pop() = 0;

    virtual bool isEmpty() = 0;
};

#endif // STACK_H
