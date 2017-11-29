//
// Created by samson on 17-10-24.
//

#ifndef LEARN_ARRAYLIST_H
#define LEARN_ARRAYLIST_H

#include <sstream>
#include "linear_list.h"
#include "iostream"
#include "../exception/my_exception.h"

using namespace std;

template <class T>
class ArrayList : LinearList<T> {
public:
    ArrayList(int inputMaxSize = 10) {
        if (inputMaxSize <= 0) {
            cout << "maxSize要大于0，目前是：" << inputMaxSize <<"，将被初始化为10"<< endl;
            inputMaxSize = 10;
        }
        maxSize = inputMaxSize;
        length = 0;
        elements = new T[maxSize];
    }

    ArrayList(const ArrayList<T>& target) {
        maxSize = target.maxSize;
        length = target.length;
        elements = new T[maxSize];
        copy(target.elements, target.elements + length, elements);
    }

    ~ArrayList() {delete [] elements;}

    //ADT中定义的方法
    bool isEmpty() const { return length == 0;}

    int getLength() const { return length;}

    T& get(int k) const {
        checkIndex(k);
        return elements[k];
    }

    int search(const T& target) const {
//        int theIndex = (int) (find(elements, elements + length, target) - elements);
        for (int i = 0; i < length; i++) {
            if (elements[i] == target)
                return i;
        }
        return -1;
    }

    T& remove(int key) {
        checkIndex(key);
        T &value = elements[key];

        for (int i = key+1; i < length; i++) {
            elements[i-1] = elements[i];
        }
        elements[--length].~T();

        return value;
    }

    void insert(int index, const T& value) {
        if (index < 0 || index > length) {
            ostringstream s;
            s << "index=" << index << "当前长度为:" << length << endl;
            throw IllegalIndex(s.str());
        }

        checkAndDoubleList();

        for (int i = length; i > index; i--) {
            elements[i] = elements[i-1];
        }
        elements[index] = value;
        length++;
    }

    void append(const T& value) {
        checkAndDoubleList();

        elements[length++] = value;
    }

    void reverse() {
        int half = length / 2;
        for (int i = 0; i < half; i++) {
            auto *tmp = new T;
            *tmp = elements[i];
            elements[i] = elements[length-1 - i];
            elements[length-1 - i] = *tmp;
            delete tmp;
        }
    }

//    void output(ostream &out) const {
//        for (int i = 0; i < length; ++i)
//            out << elements[i] << " ";
//    }

//    ostream& operator<<(ostream& out, const ArrayList<T>& x) {
//        x.output(out);
//        return out;
//    }

    ArrayList& merge(const ArrayList &a, const ArrayList &b) {

        int aK = 0, bK = 0;
        int aSize = a.getLength(), bSize = b.getLength();

        ArrayList<T> ans( (aSize + bSize) * 2);
        while (aK < aSize && bK < bSize) {
            if (a.get(aK) < b.get(bK))
                ans.append(a.get(aK++));
            else
                ans.append(b.get(bK++));
        }
        if (aK == aSize)
            for (int i = bK; i < bSize; ++i)
                ans.append(b.get(i));
        else
            for (int i = aK; i < aSize; ++i)
                ans.append(a.get(i));

        return ans;
    }

private:
    int length;
    int maxSize;
    T *elements;

    void checkAndDoubleList() {
        if (length == maxSize) {
            auto *newEles = new T[maxSize*2];
            for (int i = 0; i < length; i++) {
                newEles[i] = elements[i];
            }
            maxSize = maxSize * 2;
        }
    }

    void checkIndex(int theIndex) const {
        if (theIndex < 0 || theIndex >= length) {
            ostringstream s;
            s << "index=" << theIndex << "当前长度为:" << length << endl;
            throw IllegalIndex(s.str());
        }
    }
};

#endif //LEARN_ARRAYLIST_H