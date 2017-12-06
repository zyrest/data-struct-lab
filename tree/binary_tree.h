//
// Created by samson on 17-12-6.
//

#ifndef LEARN_BINARY_TREE_H
#define LEARN_BINARY_TREE_H
#include "iostream"
using namespace std;

template <class T>
struct BTNode {
    T element;
    BTNode<T> *leftChild;
    BTNode<T> *rightChild;

    BTNode() {
        leftChild = rightChild = nullptr;
    }

    BTNode(const T& ele) {
        element = ele;
        leftChild = rightChild = nullptr;
    }

    BTNode(const T& ele, BTNode<T> *left, BTNode<T> *right) {
        element = ele;
        leftChild = left;
        rightChild = right;
    }
};
template <class T>
class BinaryTree {
public:
    void visit(BTNode<T> *x) {
        cout << x->element << " ";
    }

    void preOrder(BTNode<T> *t) {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
private:

};
#endif //LEARN_BINARY_TREE_H
