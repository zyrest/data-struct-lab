#include <iostream>
#include "experments/sort.h"
#include "./list/list.h"
#include "./matrix/tridiagonal_matrix.h"
#include "./matrix/lowdiagonal_matrix.h"
#include "matrix/sparse_matrix.h"
#include "stack/stack.h"
#include "dict/hash_table.h"
#include "queue/queue.h"
#include "tree/binary_tree.h"
#include "heap/heap.h"
#include "tree/binary_search_tree.h"
#include "graph/graph.h"

using namespace std;

void caculate(const char* inputs, int len);
bool findMazePath(int **maze, int rowSize, int colSize);
void mazePath();
void inputMinPath(int **grid, int sx, int sy, int ex, int ey, int rowSize, int colSize);

BinaryTree<int>* buildHuffmanTree(int weight[], int n);

//实验一
void testAllSort();
void testChild();

//实验二
void testSort() {
    auto *iSort = new Sorts<int>();

    int arr1[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    iSort->selectSort(arr1, len);

    int arr2[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    iSort->bubbleSort(arr2, len);

    int arr3[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    iSort->insertSort(arr3, len);

    int arr4[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    iSort->basisSort(arr4, 5, len);

    int arr5[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    iSort->quickSort(arr5, len);

    int arr6[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    iSort->mergeSort(arr6, len);
}

//实验三
void testChainList() {
//    auto *list = new ChainList<int>();
//
//    list->append(0);
//    for (int i = 0; i < 10; ++i) {
//        list->append(2*i);
//    }
//    list->append(55);
//
//    int& a = list->get(0);
//    a = 88;
//
//    list->reverse();
//    list->output(cout);
}

//实验四
void testTridiagonalMatrix() {
    TridiagonalMatrix<int> matrix(5);
    int v = 66;
    matrix.store(0,0,v);
    matrix.store(0,1,v);
    matrix.store(1,0,v);
    matrix.store(3,3,v);
    matrix.output();
}
void testLow() {
    LowdiagonalMatrix<int> matrix(5);
    int v = 99;
    matrix.store(0, 0, v);
    matrix.store(1, 1, v);
    matrix.store(2, 2, v);
    matrix.store(3, 3, v);
    matrix.store(4, 4, v);
    matrix.output();
}
void testSparse() {
    auto *matrix = new SparseMatrix<int>(5,5);
    int v = 666;
    matrix->store(3,4,v);
    matrix->store(2,3,v);
    matrix->store(1,2,v);
    matrix->store(0,1,v);
    matrix->store(0,0,v);
    matrix->output();

    auto *a = new SparseMatrix<int>(5,5);
    int q = 111;
    a->store(3,4,q);
    a->store(2,3,q);
    a->store(1,2,q);
    a->store(0,1,q);
    a->store(0,0,q);
    a->store(1,0,q);
    cout << "\n" << endl;
    cout << "稀疏矩阵相加" << endl;
    a->output();
    cout << endl;
    matrix->output();
    cout << endl;
    matrix->add(*a);
    matrix->output();

    cout << "\n" << endl;
    cout << "转置" << endl;
    matrix->transpose();
    matrix->output();

}
void testLinearHash() {
    LinearHashTable<int> table(916);
    for (int i = 1; i <= 500; ++i) {
        table.insert(i*32, i+1);
    }

    cout << table.find(64)->value << endl;
}

//实验五
void testCal() {
    char inp[] = "2+3*(4+5*2)-6/3";
    int len = (sizeof(inp) / sizeof(inp[0])) - 1;
//    cout << "计算表达式长度为：" << len << endl;
    caculate(inp, len);
}
void testFindMazePath() {
    int mz[12][12] =
            {
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,1,1,1,1,1,0,0,0,0,1},
                    {1,0,0,0,0,0,1,0,1,0,0,1},
                    {1,0,0,0,1,0,1,0,0,0,0,1},
                    {1,0,1,0,1,0,1,0,1,1,0,1},
                    {1,0,1,0,1,0,1,0,1,0,0,1},
                    {1,0,1,1,1,0,1,0,1,0,1,1},
                    {1,0,1,0,0,0,1,0,1,0,1,1},
                    {1,0,1,0,1,1,1,0,1,0,0,1},
                    {1,1,0,0,0,0,0,0,1,0,0,1},
                    {1,0,0,0,0,1,1,1,1,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}
            };

    findMazePath((int**)mz, 12, 12);
}
void testFindMinPath() {
    int mz[12][12] =
            {
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,1,1,1,1,1,0,0,0,0,1},
                    {1,0,0,0,0,0,1,0,1,0,0,1},
                    {1,0,0,0,1,0,1,0,0,0,0,1},
                    {1,0,1,0,1,0,1,0,1,1,0,1},
                    {1,0,1,0,1,0,1,0,1,0,0,1},
                    {1,0,1,1,1,0,1,0,1,0,1,1},
                    {1,0,1,0,0,0,1,0,1,0,1,1},
                    {1,0,1,0,1,1,1,0,1,0,0,1},
                    {1,1,0,0,0,0,0,0,1,0,0,1},
                    {1,0,0,0,0,1,1,1,1,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}
            };

    inputMinPath((int**)mz, 2,1, 5,3, 12, 12);
}

//实验六
void testBinaryTree() {
    BTNode<int> *one = new BTNode<int>(1);
    BTNode<int> *two = new BTNode<int>(2);
    BTNode<int> *thr = new BTNode<int>(3);
    BTNode<int> *fou = new BTNode<int>(4);
    BTNode<int> *fiv = new BTNode<int>(5);
    BTNode<int> *six = new BTNode<int>(6);
    one->leftChild = two;
    one->rightChild = thr;
    two->leftChild = fou;
    two->rightChild = fiv;
    thr->leftChild = six;

    BinaryTree<int> tree(one);
    cout << "前序遍历结果为：";tree.preOrder(one);
    cout << endl;

    cout << "中序遍历结果为：";tree.inOrder(one);
    cout << endl;

    cout << "后序遍历结果为：";tree.postOrder(one);
    cout << endl;

    cout << "层次遍历结果为：";tree.levelOrder(one);
    cout << endl;

    cout << "二叉树节点个数：" << tree.getSize(one) << endl;

    cout << "二叉树高度：" << tree.getHeight(one) << endl;

    cout << "获得后序遍历:";
    char pre[] = {'1','2','4','5','3','6'};
    char in[] = {'4','2','5','1','6','3'};
    tree.getPostFromPreAndIn(pre, in, 6);
}
void testArrayStack() {
    ArrayStack<int> stack(20);
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while (! stack.isEmpty()) {
        cout << stack.pop() << endl;
    }
}
void testFourFiveSix() {
    cout << "下三角矩阵：" << endl;
    testLow();
    cout << endl;

    cout << "三对角矩阵：" << endl;
    testTridiagonalMatrix();
    cout << endl;

    cout << "稀疏矩阵：" << endl;
    testSparse();
    cout << endl;

    cout << "散列表：" << endl;
    testLinearHash();
    cout << endl;

    cout << "计算表达式：" << endl;
    testCal();
    cout << endl;

    cout << "迷宫路径：" << endl;
    testFindMazePath();
    cout << endl;

    cout << "电路布线：" << endl;
    testFindMinPath();
    cout << endl << endl;

    cout << "二叉树：" << endl;
    testBinaryTree();
    cout << endl;
}

//实验七
void testMaxHeap() {
    cout << "测试最大堆类（插入，删除，初始化）：" << endl;
    MaxHeap<int> heap(20);
    heap.push(123);
    heap.push(234);
    heap.push(233);
    heap.push(901);
    heap.push(1);
    heap.push(6);
    heap.push(666);

    cout << "层次遍历当前最大堆：" << endl;
    heap.output();
    cout << endl;
    cout << "依次取出堆顶元素：" << endl;
    while (!heap.isEmpty()) {
        cout << heap.pop() << " ";
    }

    cout << "初始化最大堆：" << endl;
    int arr[] = {0,12,323,421,5435,2,33,99};
    heap.initialize(arr, 7);
    cout << "层次遍历初始化后的堆：" << endl;
    heap.output();
    cout << endl;
    cout << "依次取出初始化后的堆顶元素：" << endl;
    while (!heap.isEmpty()) {
        cout << heap.pop() << " ";
    }
    cout << endl;
}
void testHuffman() {
    cout << "测试霍夫曼树：" << endl;
    int arr[] = {3,12,323,421,5435,2,33,99};

    BinaryTree<int> *tree = buildHuffmanTree(arr, 7);
    tree->huffmanOutput(tree->root);
}
void testSearchTree() {
    cout << "测试二叉搜索树：" << endl;
    BinarySearchTree<int, int> bTree;
    bTree.push(1, 5);
    bTree.push(2, 10);
    bTree.push(3, 15);
    bTree.push(4, 22);

    cout << bTree.find(4) << " " << bTree.find(0) << endl;
}
void testHeapSort() {
    cout << "测试堆排序：" << endl;
    cout << "原数组为：{6,122,323,421,5435,234,0,99}" << endl;
    int arr[] = {-1,6,122,323,421,5435,234,0,99};
    int len = sizeof(arr) / sizeof(arr[0]);

    MinHeap<int> heap(len);
    heap.initialize(arr, len-1);
    int ans[len];
    cout << "排序结果为：" << endl;
    for (int i = 1; i < len; ++i) {
        ans[i] = heap.pop();
        cout << ans[i] << " ";
    }
    cout << endl;
}

//实验八
void testGraph() {
    int n = 5;
    LinkedGraph g(n);

    Edge a(1,2);
    g.addEdge(a);

    a.i = 2; a.j = 3;
    g.addEdge(a);

    a.i = 2; a.j = 4;
    g.addEdge(a);

    a.i = 1; a.j = 5;
    g.addEdge(a);

    int reach[n+1];
    for (int &i : reach) i = 0;
    int label = 99;

    g.dfsGTree();
//    g.dfs(1, reach, label);
//    for (int j = 1; j <= n; ++j) {
//        cout << reach[j] << " ";
//    }

}
int main() {
    testGraph();
    return 0;
}