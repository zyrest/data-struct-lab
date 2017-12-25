//
// Created by samson on 17-12-6.
//

#ifndef LEARN_BINARY_TREE_H
#define LEARN_BINARY_TREE_H
#include "iostream"
#include "../queue/queue.h"
#include "../list/list.h"

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

    friend ostream& operator<< (ostream &os,BTNode<T> &node) {
        os << "{" << node.element << "}";
//        os <<", left={" << node.leftChild->element << "}, right={" << node.rightChild->element << "}";
        return os;
    }
};

template <class T>
class BinaryTree {
public:
    BinaryTree() = default;

    explicit BinaryTree(const T& r) {
        root = new BTNode<T>(r);
    }

    explicit BinaryTree(BTNode<T>* r) {
        root = r;
    }

    void visit(BTNode<T> *x) {
        cout << x->element << " ";
    }

    void preOrder(BTNode<T> *t) {
        if (t != nullptr) {
            visit(t);
            preOrder(t->leftChild);
            preOrder(t->rightChild);
        }
    }

    void inOrder(BTNode<T> *t) {
        if (t != nullptr) {
            inOrder(t->leftChild);
            visit(t);
            inOrder(t->rightChild);
        }
    }

    void postOrder(BTNode<T> *t) {
        if (t != nullptr) {
            postOrder(t->leftChild);
            postOrder(t->rightChild);
            visit(t);
        }
    }

    void levelOrder(BTNode<T> *t) {
        ArrayQueue<BTNode<T>*> q;
        while (t != nullptr) {
            visit(t);

            if (t->leftChild != nullptr) q.push(t->leftChild);
            if (t->rightChild != nullptr) q.push(t->rightChild);

            try {
                t = q.front();
            } catch (Empty) {
                return;
            }
            q.pop();
        }
    }

    int getHeight(BTNode<T> *t) {
        if (t == nullptr) return 0;
        int hl = getHeight(t->leftChild);
        int hr = getHeight(t->rightChild);
        return (hl > hr) ? ++hl : ++hr;
    }

    int getSize(BTNode<T> *t) {
        if (t == nullptr) return 0;
        int sl = getSize(t->leftChild);
        int sr = getSize(t->rightChild);
        return sl + sr + 1;
    }

    void getPostFromPreAndIn(char *pre, char *in, int len) {

        if(len == 0) return;

        BTNode<char> *node = new BTNode<char>;
        node->element = *pre;
        int rootIndex = 0;
        for (; rootIndex < len; ++rootIndex) {
            if (in[rootIndex] == *pre) break;
        }

        getPostFromPreAndIn(pre+1, in, rootIndex);
        getPostFromPreAndIn(pre+rootIndex+1, in+rootIndex+1, len-rootIndex-1);
        cout << node->element << " ";
    }

    void makeTree(const T& ele, BinaryTree<T>& left, BinaryTree<T>& right) {
        root = new BTNode<T>(ele, left.root, right.root);

        left.root = 0;
        right.root = 0;
    }

    void huffmanOutput(BTNode<T> *t) {
        if (t->element != 0) {
            cout << "{" << t->element << "}"  << endl;
            return;
        }

        cout << 0 << " ";
        huffmanOutput(t->leftChild);

        cout << 1 << " ";
        huffmanOutput(t->rightChild);
    }

    BTNode<T> *root;
};
#endif //LEARN_BINARY_TREE_H
