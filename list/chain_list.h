//
// Created by samson on 17-10-26.
//

#ifndef LEARN_CHAINLIST_H
#define LEARN_CHAINLIST_H

#include "linear_list.h"

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
        T result = NULL;
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


#endif //LEARN_CHAINLIST_H
