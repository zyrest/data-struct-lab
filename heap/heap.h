//
// Created by 96428 on 2017/12/25.
//

#ifndef LEARN_HEAP_H
#define LEARN_HEAP_H

#include "../exception/my_exception.h"
#include "iostream"
using namespace std;

template <class T>
class MaxHeap {
public:
    explicit MaxHeap(int s) {
        maxSize = s;
        current = 0;
        elements = new T[s];
    }

    void push(const T& ele) {
        checkAndDoubleList();

        int index = ++current;
        while (index != 1 && elements[index/2] < ele) {
            elements[index] = elements[index/2];
            index /= 2;
        }

        elements[index] = ele;
    }

//    T& front() {
//        return elements[1];
//    }

    T& pop() {
        if (current == 0) throw Empty("empty");

        T *ans = new T();
        *ans = elements[1];
        elements[1].~T(); //返回最大值

        T lastEle = elements[current--]; //删除最后的元素，为其找个位置
        int index = 1;
        int child = 2;
        while (child <= current) { //从顶向下寻找lastEle应该放的位置
            if (child < current && elements[child] < elements[child+1])
                child++; //确保child为index的儿子中最大的一个

            //大于最大的儿子，已经找到正确的位置
            if (lastEle >= elements[child])
                break;

            //小于最大的儿子，将儿子上移
            elements[index] = elements[child];
            index = child;//index位置永远为空
            child *= 2;
        }
        elements[index] = lastEle;

        return *ans;
    }

    void initialize(T *theHeap, int theSize) {
        delete[] elements;
        elements = theHeap;
        current = theSize;

        for (int root = current/2; root >= 1; root--) {
            T rootEle = elements[root];

            int child = root * 2;
            while (child <= current) {
                if (child < current && elements[child] < elements[child+1])
                    child++; //确保child为index的儿子中最大的一个

                //大于最大的儿子，已经找到正确的位置
                if (rootEle >= elements[child])
                    break;

                //小于最大的儿子，将儿子上移
                elements[child/2] = elements[child];
                child *= 2;
            }
            elements[child/2] = rootEle;
        }
    }

    bool isEmpty() {
        return current == 0;
    }

    void output() {
        for (int i = 1; i <= current; ++i) {
            cout << elements[i] << " ";
        }
    }
private:
    T *elements;
    int maxSize;
    int current;

    void checkAndDoubleList() {
        if (current == maxSize-1) {
            auto *newEles = new T[maxSize*2];
            for (int i = 0; i < current; i++) {
                newEles[i] = elements[i];
            }

            maxSize = maxSize * 2;
            delete[] elements;
            elements = newEles;
        }
    }
};


template <class T>
class MinHeap {
public:
    explicit MinHeap(int s) {
        maxSize = s;
        current = 0;
        elements = new T[s];
    }

    void push(const T& ele) {
        checkAndDoubleList();

        int index = ++current;
        while (index != 1 && elements[index/2] > ele) {
            elements[index] = elements[index/2];
            index /= 2;
        }

        elements[index] = ele;
    }

//    T& front() {
//        return elements[1];
//    }

    T& pop() {
        if (current == 0) throw Empty("empty");

        T *ans = new T();
        *ans = elements[1];
        elements[1].~T(); //返回最大值

        T lastEle = elements[current--]; //删除最后的元素，为其找个位置
        int index = 1;
        int child = 2;
        while (child <= current) { //从顶向下寻找lastEle应该放的位置
            if (child < current && elements[child] > elements[child+1])
                child++; //确保child为index的儿子中最小的一个

            //小于最小的儿子，已经找到正确的位置
            if (lastEle <= elements[child])
                break;

            //大于最小的儿子，将儿子上移
            elements[index] = elements[child];
            index = child;//index位置永远为空
            child *= 2;
        }
        elements[index] = lastEle;

        return *ans;
    }

    void initialize(T *theHeap, int theSize) {
        delete[] elements;
        elements = theHeap;
        current = theSize;

        for (int root = current/2; root >= 1; root--) {
            T rootEle = elements[root];

            int child = root * 2;
            while (child <= current) {
                if (child < current && elements[child] > elements[child+1])
                    child++; //确保child为index的儿子中最大的一个

                //大于最大的儿子，已经找到正确的位置
                if (rootEle <= elements[child])
                    break;

                //小于最大的儿子，将儿子上移
                elements[child/2] = elements[child];
                child *= 2;
            }
            elements[child/2] = rootEle;
        }
    }

    bool isEmpty() {
        return current == 0;
    }

    void output() {
        for (int i = 1; i <= current; ++i) {
            cout << elements[i] << " ";
        }
    }
private:
    T *elements;
    int maxSize;
    int current;

    void checkAndDoubleList() {
        if (current == maxSize-1) {
            auto *newEles = new T[maxSize*2];
            for (int i = 0; i < current; i++) {
                newEles[i] = elements[i];
            }

            maxSize = maxSize * 2;
            delete[] elements;
            elements = newEles;
        }
    }
};
#endif //LEARN_HEAP_H
