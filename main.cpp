#include <iostream>
#include "list/linear_list.h"
#include "list/array_list.h"
#include "./experments/two.h"
#include "./list/chain_list.h"
#include "./matrix/tridiagonal_matrix.h"
#include "./matrix/lowdiagonal_matrix.h"
#include "matrix/sparse_matrix.h"
#include "stack/arrayStack.h"

using namespace std;

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

void testTridiagonalMatrix() {
    TridiagonalMatrix<int> matrix(5);
    int v = 66;
    matrix.store(0,0,v);
    matrix.store(0,1,v);
    matrix.store(1,0,v);
    matrix.store(3,3,v);
    matrix.output();
}

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

//void testArrayList() {
//    //使用构造方法构造两个list
//    auto list1 = new ArrayList<int>(11);
//    ArrayList<double> list2(50);
//
//    //使用缺省值构造list
//    ArrayList<long> list3;
//
//    //使用复制构造方法构造list
//    ArrayList<long> list4(list3);
//
//    ArrayList<int> one(10);
//    ArrayList<int> two(55);
//
//    two.append(0);
//    for (int i = 0; i < 10; ++i) {
//        one.append(2*i);
//        two.append(2*i+1);
//    }
//    two.append(55);
//
//    ArrayList<int> three = one.merge(one, two);
//    for (int j = 0; j < three.getLength(); ++j) {
//        cout << three.get(j) << endl;
//    }
//
//    for (int i = 0; i < 11; ++i) {
//        list1->append(i);
//    }
//    for (int j = 0; j < 11; ++j) {
//        cout << list1->get(j) << endl;
//    }
//    list1->reverse();
//    for (int k = 0; k < 11; ++k) {
//        cout << list1->get(k) << endl;
//    }
//}

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

int main() {
//    testChild();
//    testAllSort();

//    int arr[] = {54,43,22,112,3,82,7,9,77099,99,785,336};
//    int len = sizeof(arr) / sizeof(arr[0]);
//
//    auto *iSort = new Sorts<int>();
//    iSort->quickSort(arr, len);

    testArrayStack();
    return 0;
}



