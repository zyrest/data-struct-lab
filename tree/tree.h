//
// Created by 96428 on 2017/12/24.
//

#ifndef LEARN_TREE_H
#define LEARN_TREE_H
#include "iostream"
#include "../queue/queue.h"
#include "../list/list.h"

using namespace std;

template <class K, class V>
struct NodePair {
    K key;
    V value;

    NodePair() = default;

    NodePair(const K& k, const V& v) {
        key = k;
        value = v;
    }
};

template <class K, class V>
struct TreeNode {
    NodePair<K, V> element;
    TreeNode<K, V> *left;
    TreeNode<K, V> *right;
};

template <class K, class V>
class BinarySearchTree {
public:
    BinarySearchTree(){
        treeSize = 0;
        root = nullptr;
    }

    void push(const K& key, const V& value) {
        NodePair<K, V> pair(key, value);

        TreeNode<K, V> *p = root, *pp = nullptr;
        while (p != nullptr) {
            pp = p;
            if (pair.key < p->element.key)
                p = p->left;
            else if (pair.key > p->element.key)
                p = p->right;
            else {
                p->element.value = pair.value;
                return;
            }
        }

        TreeNode<K, V> *newNode = new TreeNode<K, V>();
        newNode->element = pair;
        if (root != nullptr)
            if (pair.key < pp->element.key)
                pp->left = newNode;
            else
                pp->right = newNode;
        else
            root = newNode;

        treeSize++;
    }

    V& find(const K& key) {
        TreeNode<K, V> *p = root;

        while (p != nullptr) {
            if (key < p->element.key)
                p = p->left;
            else if (key > p->element.key)
                p = p->right;
            else
                return p->element.value;
        }

        return *(new V());
    }

private:
    TreeNode<K, V> *root;
    int treeSize;
};

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

    void makeTree(const T& ele) {
        root = new BTNode<T>(ele, nullptr, nullptr);
    }

    void huffmanOutput(BTNode<T> *t,int *base, int i) {

        if(t->leftChild == nullptr && t->rightChild == nullptr) {
            for(int j=0; j<10 && base[j]!=-1; j++)
                cout << base[j] << " ";
            cout << "{" << t->element << "}" << endl;
            return;
        } else {
            if (t->leftChild != nullptr) {
                base[i]=0;
                huffmanOutput(t->leftChild, base, i+1);
            }
            if (t->rightChild != nullptr) {
                base[i]=1;
                huffmanOutput(t->rightChild, base, i+1);
            }
            base[i] = -1;
        }
    }

    BTNode<T> *root;
};
#endif //LEARN_TREE_H
