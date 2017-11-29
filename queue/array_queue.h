//
// Created by samson on 17-11-29.
//

#ifndef LEARN_ARRAY_QUEUE_H
#define LEARN_ARRAY_QUEUE_H

#include "queue.h"

template <class T>
class ArrayQueue : public Queue<T> {
public:
    explicit ArrayQueue(int init = 10) {
        queue = new T[init];
        queueLength = init;
        qFront = qBack = -1;
    }
    bool isEmpty() const override {
        return qFront == qBack;
    }

    int getSize() const override {
        return (qBack - qFront) % queueLength;
    }

    T &front() override {
        return <#initializer#>;
    }

    T &pop() override {
        return <#initializer#>;
    }

    void push(const T &element) override {

    }

private:
    int qFront;
    int qBack;
    int queueLength;
    T *queue;
};
#endif //LEARN_ARRAY_QUEUE_H
