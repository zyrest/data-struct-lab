//
// Created by samson on 17-11-29.
//

#ifndef LEARN_ARRAY_QUEUE_H
#define LEARN_ARRAY_QUEUE_H

#include <queue>
#include <regex>
#include "queue.h"
#include "../exception/my_exception.h"

template <class T>
class ArrayQueue : public Queue<T> {
public:
    explicit ArrayQueue(int init = 10) {
        queue = new T[init];
        arrayLength = init;
        qFront = 0;
        qBack = 0;
    }
    bool isEmpty() const override {
        return qFront == qBack;
    }

    int getSize() const override {
        return (qBack - qFront - 1) % arrayLength;
    }

    T &front() override {
        if (isEmpty()) throw Empty("队列已满");
        int index = (qFront + 1) % arrayLength;

        return queue[index];
    }

    T &pop() override {
        if (isEmpty()) throw Empty("队列已满");
        qFront = (qFront + 1) % arrayLength;

        return queue[qFront];
    }

    void push(const T &element) override {
        if ((qBack+1) % arrayLength == qFront) doubleSize();
        qBack = (qBack+1) % arrayLength;
        queue[qBack] = element;
    }

private:
    int qFront;
    int qBack;
    int arrayLength;
    T *queue;

    void doubleSize() {
        T *n = new T[arrayLength * 2];

        int start = (qFront+1) % arrayLength;
        if (start < 2) {
            for (int i = 0; i < arrayLength; ++i) {
                n[i] = queue[(start++) % arrayLength];
            }
        } else {
            int c = 0;
            for (int i = start; i < arrayLength; ++i) {
                n[c++] = queue[i];
            }
            for (int j = 0; j <= qBack; ++j) {
                n[c++] = queue[j];
            }
        }

        qFront = arrayLength*2 - 1;
        qBack = arrayLength - 2;
        arrayLength *= 2;
        delete[] queue;
        queue = n;
    }
};
#endif //LEARN_ARRAY_QUEUE_H
