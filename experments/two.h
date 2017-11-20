//
// Created by samson on 17-11-1.
//

#ifndef LEARN_TWO_H
#define LEARN_TWO_H

#include <iostream>
#include <cmath>

using namespace std;

template<class T>
class Sorts {
public:
    void selectSort(T *arr, int len) {
        cout << "进入选择排序，目前元素顺序为 ：" << endl;
        showArray(arr, len);
        cout << "\n" << endl;

        for (int i = 0; i < len; ++i) {
            T min = arr[i];
            int index = i;

            cout << "前" << i << "个元素已经排好序，正在寻找后" << len-i << "个元素的最小值" << endl;
            cout << "初始认为第" << i+1 << "个元素为最小，值为：" << min << endl;
            for (int j = i+1; j < len; ++j) {
                if (arr[j] < min) {
                    cout << "第" << j+1 << "个元素的值小于min，值为：" << arr[j] << "，小于当前最小值min：" << min << endl;

                    index = j;
                    min = arr[j];
                }
            }

            cout << "交换第" << i+1 << "个元素与最小的第" << index+1 << "个元素的位置" << endl;

            swap(&arr[i], &arr[index]);

            cout << "前" << i+1 << "个元素已经排好序， 为 ：" << endl;
            showArray(arr, i+1);
            cout << "\n" << endl;
        }
    }

    void bubbleSort(T *arr, int len) {
        cout << "进入冒泡排序，目前元素顺序为 ：" << endl;
        showArray(arr, len);
        cout << "\n" << endl;

        for (int i = len; i > 1; i--) {
            cout << "当前状态下，前" << i << "个元素未排序" << endl;
            cout << "现在使第1个元素至第" << i << "个元素冒泡" << endl;

            for (int j = 0; j < i-1; ++j) {
                cout << "比较第" << j+1 << "个元素：（" << arr[j] << ")与第" << j+2 << "个元素：（" << arr[j+1] << "）" << endl;

                if (arr[j+1] < arr[j]) {
                    cout << "第" << j+1 << "个元素：（" << arr[j] << ")大于第" << j+2 << "个元素：（" << arr[j+1] << "），";
                    cout << "交换两者位置" << endl;

                    swap(&arr[j], &arr[j+1]);
                }
            }

            cout << "现在的结果是 ： " << endl;
            showArray(arr, len);
            cout << "\n" << endl;
        }
    }

    void insertSort(T *arr, int len) {
        cout << "进入插入排序，目前元素顺序为 ：" << endl;
        showArray(arr, len);
        cout << "\n" << endl;

        for (int i = 1; i < len; ++i) {
            cout << "现在将第" << i+1 << "个元素向前" << i << "个有序元素中插入" << endl;
            T tmp = arr[i];
            cout << "第" << i+1 << "个元素为" << tmp << endl;


            for (int k = i; k >= 0 ; --k) {
                cout << "比较第" << k << "个元素(" << arr[k-1] << ")与将插入的元素(" << tmp << ")" << endl;
                if (arr[k-1] > tmp) {
                    cout << "第" << k << "个元素(" << arr[k-1] << ")大于将插入的元素(" << tmp << ")" << "将其向后移动一位" << endl;
                    arr[k] = arr[k-1];
                } else {
                    cout << "第" << k << "个元素(" << arr[k-1] << ")小于等于将插入的元素(" << tmp << ")" << endl;
                    cout << "将要插入的元素放在第" << k+1 << "位上" << endl;
                    arr[k] = tmp;
                    break;
                }
                if (k == 0) {
                    cout << "所有的元素均大于要插入的元素，故将该元素插入到第一位" << endl;
                    arr[0] = tmp;
                }
            }

        }

        cout << "排序结束: " << endl;
        showArray(arr, len);

    }

    void basisSort(T *arr, int maxLen, const int len) {
        cout << "进入基数排序，目前元素顺序为 ：" << endl;
        showArray(arr, len);
        cout << "\n" << endl;

        auto **bins = new T*[10]; //初始化箱子
        for (int l = 0; l < 10; ++l) {
            bins[l] = new T[len];
        }
        auto *index = new int[10]; //每个箱子的索引数组
        cout << "初始化十个箱子\n" << endl;

        for (int j = 1; j <= maxLen; ++j) {
            for (int k = 0; k < 10; ++k) {
                index[k] = 0;
            }
            //扫描后对每一个分配到相应的箱子里去
            for (int i = 0; i < len; ++i) {
                T basis = (int)(arr[i] / pow(10, j-1)) % 10;
                cout << "扫描第" << i+1 << "个元素("<< arr[i] << ")，其第" << j << "位为" << basis << "，将其放入相应的箱子" << endl;
                bins[basis][index[basis]++] = arr[i];
            }

            //取出每个箱子里的数，排入到原数组
            int res = 0;
            for (int k = 0; k < 10; ++k) {
                cout << "取出第"<< k+1 <<"个箱子里的所有数，重新排入到原数组" << endl;
                for (int i = 0; i < index[k]; ++i) {
                    arr[res++] = bins[k][i];
                }
            }

            cout << "第" << j << "趟箱子排序结束，目前排序结果为：" << endl;
            showArray(arr, len);
            cout << "\n" << endl;
        }
        for (int m = 0; m < 10; ++m) {
            delete [] bins[m];
        }
        delete [] bins;
        delete [] index;
    }

    void quickSort(T *arr, int len) {
        cout << "进入快速排序，目前元素顺序为 ：" << endl;
        showArray(arr, len);
        cout << endl;

        int maxIndex = 0;
        for (int i = 1; i < len; ++i) {
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        cout << "首先找到最大值->" << arr[maxIndex] << ",将其放到最后一位\n" << endl;
        swap(&arr[maxIndex], &arr[len - 1]);

        cout << "递归全体" << "第1位(" << arr[0] << ")到第" << len <<"位(" << arr[len-1] << ")" << "，过程为：" << endl;
        quickSort(arr, 0, len - 1);

        cout << "快速排序结束，结果为： " << endl;
        showArray(arr, len);
    }

    void mergeSort(T *arr, int len) {
        auto *brr = new T[len];
        int segmentSize = 1;
        while (segmentSize < len) {
            mergePass(arr, brr, len, segmentSize);
            segmentSize += segmentSize;
            mergePass(brr, arr, len, segmentSize);
            segmentSize += segmentSize;
        }
        delete []brr;

        showArray(arr, len);
    }

private:
    void swap(T *a, T *b) {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void showArray(T *arr, int len) {
        for (int k = 0; k < len; ++k) {
            cout << arr[k] << ((k == len-1) ? "" : " ");
        }
    }

    void quickSort(T *arr, int start, int end) {

        //若len为1返回
        if (start >= end) {
            cout << "左起点(" << start+1 << "),与右终点("<< end+1 <<")->递归出口\n" << endl;
            return;
        }

        //找到一个值，使其左边小于他，右边大于他，假定就是最后一个数
        int left = start + 1;
        int mid = arr[start];
        int right = end;
        cout << "认为第" << start+1 << "位(" << arr[start] << ")" << "为pivort" << endl;

        while (true) {
            while (arr[left] < mid) {
                left++;
            }
            while (arr[right] > mid) {
                right--;
            }
            if (left >= right) break;
            swap(&arr[right], &arr[left]);
        }

        arr[start] = arr[right];
        arr[right] = mid;

        showArray(arr, 12);
        cout << "\n" << endl;

        //递归两侧
        cout << "递归左侧" << "第" << start+1 << "位(" << arr[start] << ")到第" << right <<"位(" << arr[right-1] << ")" << "， 过程为：" << endl;
        quickSort(arr, start, right - 1);
        cout << "递归右侧" << "第" << right+2 << "位(" << arr[right+1] << ")到第" << end+1 <<"位(" << arr[end] << ")" << "， 过程为：" << endl;
        quickSort(arr, right + 1, end);
    }

    void mergePass(T *arr, T *brr, int len, int segmentSize) {
        int i = 0;
        while (i <= len - segmentSize*2) { //跳出循环的条件：完美结束，不够两格了
            merge(arr, brr, i, i + segmentSize-1, i + 2*segmentSize-1);
            i = i + 2*segmentSize;
        }

        if (i + segmentSize < len) //还有一格多，将这些合并
            merge(arr, brr, i, i + segmentSize-1, len - 1);
        else //还有 （0 - 一格），直接合并过去
            for (int j = i; j < len; ++j)
                brr[j] = arr[j];
    }

    void merge(T *src, T *tar, int startOfFirst, int endOfFirst, int endOfSecond) {
        int first = startOfFirst,
            second = endOfFirst + 1,
            result = startOfFirst;

        while ((first <= endOfFirst) && (second <= endOfSecond)) {
            if(src[first] <= src[second])
                tar[result++] = src[first++];
            else
                tar[result++] = src[second++];
        }

        if (first > endOfFirst)
            for (int i = second; i <= endOfSecond; ++i)
                tar[result++] = src[i];
        else
            for (int j = first; j <= endOfFirst; ++j)
                tar[result++] = src[j];
    }

};
#endif //LEARN_TWO_H