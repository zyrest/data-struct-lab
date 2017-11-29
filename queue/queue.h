//
// Created by samson on 17-11-29.
//

#ifndef LEARN_QUEUE_H
#define LEARN_QUEUE_H

template <class T>
class Queue {
public:
    virtual ~Queue() = default;

    virtual bool isEmpty() const = 0;

    virtual int getSize() const = 0;

    virtual T& front() = 0;

    virtual T& pop() = 0;

    virtual void push(const T& element) = 0;
};
#endif //LEARN_QUEUE_H
