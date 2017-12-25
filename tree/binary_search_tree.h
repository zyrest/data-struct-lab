//
// Created by 96428 on 2017/12/19.
//

#ifndef LEARN_BINARY_SEARCH_TREE_H
#define LEARN_BINARY_SEARCH_TREE_H
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
#endif //LEARN_BINARY_SEARCH_TREE_H
