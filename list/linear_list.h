//
// Created by samson on 17-10-24.
//

#ifndef LEARN_LINEARLIST_H
#define LEARN_LINEARLIST_H
#include "iostream"

using namespace std;

template<class T>
class LinearList{
public:
    virtual ~LinearList() = default;

    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual T& get(int k) const = 0;
    virtual int search(const T& target) const = 0;
    virtual T& remove(int key) = 0;
    virtual void insert(int index, const T& value) = 0;
    virtual void append(const T& value) = 0;
//    virtual void output(ostream& out) const = 0;
//    virtual void reverse() = 0;
};

#endif //LEARN_LINEARLIST_H
