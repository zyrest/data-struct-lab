#include <iostream>
#include "list/linear_list.h"
#include "list/array_list.h"
#include "experments/sort.h"
#include "./list/chain_list.h"
#include "./matrix/tridiagonal_matrix.h"
#include "./matrix/lowdiagonal_matrix.h"
#include "matrix/sparse_matrix.h"
#include "stack/arrayStack.h"
#include "dict/hash_table.h"
#include "queue/array_queue.h"

using namespace std;

void caculate(const char* inputs, int len);
bool findMazePath(int **maze, int rowSize, int colSize);
void mazePath();

//实验一
void testAllSort();
void testChild();

//实验二
void testSort() {
    int arr[] = {54, 43, 22, 112, 3, 82, 7, 9, 77099, 99, 785, 336};
    int len = sizeof(arr) / sizeof(arr[0]);

    auto *iSort = new Sorts<int>();
    iSort->quickSort(arr, len);
}

//实验三
void testChainList() {
    auto *list = new ChainList<int>();

    list->append(0);
    for (int i = 0; i < 10; ++i) {
        list->append(2*i);
    }
    list->append(55);

    int& a = list->get(0);
    a = 88;

    list->reverse();
    list->output(cout);
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
    cout << "\n" << endl;
    matrix->transpose();
    matrix->output();

//    auto *a = new SparseMatrix<int>(5,5);
//    int q = 111;
//    a->store(3,4,q);
//    a->store(2,3,q);
//    a->store(1,2,q);
//    a->store(0,1,q);
//    a->store(0,0,q);
//    a->store(1,0,q);
//
//    matrix->add(*a);
//    cout << "\n" << endl;
//    matrix->output();
}
void testLinearHash() {
    LinearHashTable<int> table(916);
    for (int i = 1; i <= 500; ++i) {
        table.insert(i*32, i+1);
    }

    cout << table.find(32)->value << endl;
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

void testArrayQueue() {
    ArrayQueue<int> queue(2);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(5);
    queue.push(6);
    while (!queue.isEmpty()) {
        cout << queue.pop() << endl;
        cout << queue.isEmpty() << endl;
    }
}
int main() {
    testArrayQueue();
    return 0;
}