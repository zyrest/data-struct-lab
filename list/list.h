//
// Created by 96428 on 2017/12/25.
//

#ifndef LEARN_LIST_H
#define LEARN_LIST_H

#include <sstream>
#include "iostream"
#include "../exception/my_exception.h"

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

template <class T>
class ArrayList : LinearList<T> {
public:
    explicit ArrayList(int inputMaxSize = 10) {
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
            delete[] elements;
            elements = newEles;
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


template <class T>
struct ChainNode {
    T element;
    ChainNode<T> *next;

    ChainNode() = default;

    explicit ChainNode(const T& ele) {
        element = ele;
        next = NULL;
    }
    ChainNode(const T& ele, ChainNode<T>* nx) {
        element = ele;
        next = nx;
    }
};

template <class T>
class ChainList : public LinearList<T> {
public:
    bool isEmpty() const override { return firstNode == NULL; }

    int getLength() const override { return listSize; }

    T& get(int k) const override {
        checkIndex(k);

        ChainNode<T> *tar = firstNode;//查找对应index的节点
        while (k--)
            tar = tar->next;

        return tar->element;
    }

    int search(const T &target) const override {
        ChainNode<T> *tar = firstNode;
        int key = 0;
        while (tar != NULL) {
            if (tar->element == target) break;
            tar = tar->next;
            key++;
        }

        if (key >= listSize) return -1;
        return key;
    }

    T& remove(int key) override {
        checkIndex(key);

        ChainNode<T> *tar = firstNode;
        T result;
        //删除第一个节点
        if (key == 0) {
            result = firstNode->element;
            firstNode = firstNode->next;
            delete tar;
            listSize--;
            return result;
        }
        //删除第key（>1）个节点，需要记录前一个节点，使其指向删除节点的下一个
        ChainNode<T> *pre = firstNode;
        while (key--) {
            pre = tar;
            tar = tar->next;
        }
        result = tar->element;
        pre->next = tar->next;
        tar->next = NULL;
        delete tar;
        listSize--;

        return result;
    }

    void insert(int index, const T &value) override {
        if (index < 0 || index > listSize) {
            ostringstream s;
            s << "index=" << index << "当前长度为:" << listSize << endl;
            throw IllegalIndex(s.str());
        }

        ChainNode<T> *tar = firstNode;
        ChainNode<T> *pre = firstNode;
        if (index == 0) {
            auto *insertion = new ChainNode<T>();
            insertion->element = value;
            insertion->next = firstNode;
            firstNode = insertion;
            listSize++;
            return;
        }

        while (index--) {
            pre = tar;
            tar = tar->next;
        }
        auto *insertion = new ChainNode<T>();
        insertion->element = value;
        insertion->next = tar;
        pre->next = insertion;
        listSize++;
    }

    void append(const T &value) override {
        if (firstNode == NULL) {
            auto *ele = new ChainNode<T>();
            ele->element = value;
            ele->next = NULL;
            firstNode = ele;
            listSize = 1;
            return;
        }

        int size = listSize;
        auto *tar = firstNode;
        while (--size) {
            tar = tar->next;
        }
        auto *ele = new ChainNode<T>();
        ele->element = value;
        ele->next = NULL;
        tar->next = ele;
        listSize++;
    }

    void reverse() {
        if (listSize <= 1) return;

        ChainNode<T> *pre, *now, *next_;
        pre = NULL;
        now = firstNode;
        while (now != NULL) {
            next_ = now->next;
            now->next = pre;
            pre = now;
            now = next_;
        }
        firstNode = pre;
    }

    void output(ostream &out) const  {
        for (int i = 0; i < listSize; ++i)
            out << get(i) << " ";
    }

//    ostream& operator<<(ostream &out, const ChainList<T> &x) {
//        x.output(out);
//        return out;
//    }
//
//    ChainList<T> merge(const ChainList<T> &a, const ChainList<T> &b) {
//        auto *ans = new ChainList<T>();
//        ChainNode<T> *nodeA = a.firstNode;
//        ChainNode<T> *nodeB = b.firstNode;
//
//        while (nodeA && nodeB) {
//            if (nodeA->element < nodeB->element) {
//                ans->append(nodeA->element);
//                nodeA = nodeA->next;
//            } else{
//                ans->append(nodeB->element);
//                nodeB = nodeB->next;
//            }
//        }
//        while (nodeA) {
//            ans->append(nodeA->element);
//            nodeA = nodeA->next;
//        }
//        while (nodeB) {
//            ans->append(nodeB->element);
//            nodeB = nodeB->next;
//        }
//
//        return *ans;
//    }
private:
    int listSize = 0;
    ChainNode<T> *firstNode = NULL;

    void checkIndex(int theIndex) const {
        if (theIndex < 0 || theIndex >= listSize) {
            ostringstream s;
            s << "index=" << theIndex << "当前长度为:" << listSize << endl;
            throw IllegalIndex(s.str());
        }
    }
};

#endif //LEARN_LIST_H
