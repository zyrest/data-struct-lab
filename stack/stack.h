//
// Created by samson on 17-11-29.
//

#ifndef LEARN_STACK_H
#define LEARN_STACK_H

#include "stack.h"
#include "../exception/my_exception.h"

using namespace std;

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

    void output() {
        for (int i = 0; i <= stackTop; ++i) {
            cout << stack[i] << " ";
        }
        cout << endl;
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
#endif //LEARN_STACK_H
