//
// Created by samson on 17-11-29.
//

#ifndef LEARN_ARRAYSTACK_H
#define LEARN_ARRAYSTACK_H

#include "stack.h"
#include "../exception/my_exception.h"

template <class T>
class ArrayStack : public Stack<T> {
public:

    explicit ArrayStack(int init = 10) {
        stack = new T[init];
        arrayLength = init;
        stackTop = -1;
    }

    bool isEmpty() const override {
        return stackTop == -1;
    }

    int getSize() const override {
        return stackTop+1;
    }

    T &top() override {
        if (stackTop == -1) throw Empty("当前栈为空");
        return stack[stackTop];
    }

    T &pop() override {
        if (stackTop == -1) throw Empty("当前栈为空");
        return stack[stackTop--];
    }

    void push(const T &element) override {
        if (stackTop + 1 >= arrayLength) doubleSize();
        stack[++stackTop] = element;
    }

private:
    int stackTop;
    int arrayLength;
    T *stack;

    void doubleSize() {
        auto *s = new T[arrayLength*2];
        for (int i = 0; i <= stackTop; ++i) s[i] = stack[i];
        stack = s;
        arrayLength *= 2;
    }
};
#endif //LEARN_ARRAYSTACK_H
