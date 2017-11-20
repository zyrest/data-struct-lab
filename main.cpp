#include <iostream>
#include "list/linear_list.h"
#include "list/array_list.h"
#include "./experments/two.h"
#include "./list/chain_list.h"

void testArrayList();
void testChild();
void testAllSort();
void testChainList();

using namespace std;

int main() {
//    testChild();
//    testAllSort();

//    int arr[] = {54,43,22,112,3,82,7,9,77099,99,785,336};
//    int len = sizeof(arr) / sizeof(arr[0]);
//
//    auto *iSort = new Sorts<int>();
//    iSort->quickSort(arr, len);

    testChainList();
    return 0;
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
//    list->insert(6, 56789);
    list->output(cout);
}

//void testArrayList() {
//    //使用构造方法构造两个list
//    auto list1 = new array_list<int>(11);
//    array_list<double> list2(50);
//
//    //使用缺省值构造list
//    array_list<long> list3;
//
//    //使用复制构造方法构造list
//    array_list<long> list4(list3);
//
//    array_list<int> one(10);
//    array_list<int> two(55);
//
//    two.append(0);
//    for (int i = 0; i < 10; ++i) {
//        one.append(2*i);
//        two.append(2*i+1);
//    }
//    two.append(55);
//
//    array_list<int> three = one.merge(one, two);
//    for (int j = 0; j < three.getLength(); ++j) {
//        cout << three.find(j) << endl;
//    }
//
//    for (int i = 0; i < 11; ++i) {
//        list1->append(i);
//    }
//    for (int j = 0; j < 11; ++j) {
//        cout << list1->find(j) << endl;
//    }
//    list1->reverse();
//    for (int k = 0; k < 11; ++k) {
//        cout << list1->find(k) << endl;
//    }
//}
