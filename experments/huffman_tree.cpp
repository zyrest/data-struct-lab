//
// Created by 96428 on 2017/12/19.
//

#include "../tree/tree.h"
#include "../heap/heap.h"

template <class T>
struct HuffmanNode {
    T weight;
    BinaryTree<int> *tree;

    HuffmanNode() = default;

    bool operator< (const HuffmanNode<T> &r) const {
        return weight < r.weight;
    }

    bool operator> (const HuffmanNode<T> &r) const {
        return weight > r.weight;
    }

    bool operator<= (const HuffmanNode<T> &r) const {
        return weight <= r.weight;
    }

    bool operator>= (const HuffmanNode<T> &r) const {
        return weight <= r.weight;
    }

    friend ostream& operator<< (ostream &os,HuffmanNode<T> &node) {
        os << "{" << node.weight << "}";
        return os;
    }
};

BinaryTree<int>* buildHuffmanTree(int weight[], int n) {

    auto *hNode = new HuffmanNode<int>[n+1];

    for (int i = 1; i <= n; ++i) {
        hNode[i].weight = weight[i];
        hNode[i].tree = new BinaryTree<int>();
        hNode[i].tree->makeTree(i);
    }

    MinHeap<HuffmanNode<int>> heap(n);
    heap.initialize(hNode, n);

    HuffmanNode<int> w, x, y;
    BinaryTree<int> *z;
    for (int j = 1; j < n; ++j) {
        x = heap.pop();
        y = heap.pop();

        cout << "x=" << x << ", y=" << y << ", ";
        z = new BinaryTree<int>();
        w.weight = x.weight + y.weight;
        z->makeTree(0, *x.tree, *y.tree);

        cout << "w=" << w << endl;
        w.tree = z;
        heap.push(w);
    }

    return heap.pop().tree;
}