//
// Created by samson on 17-11-29.
//

#ifndef LEARN_STACK_H
#define LEARN_STACK_H

template <class T>
class Stack {
public:
    virtual ~Stack() = default;

    virtual bool isEmpty() const = 0;

    virtual int getSize() const = 0;

    virtual T& top() = 0;

    virtual T& pop() = 0;

    virtual void push(const T& element) = 0;
};
#endif //LEARN_STACK_H
