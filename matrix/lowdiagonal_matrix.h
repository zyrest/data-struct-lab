//
// Created by samson on 17-11-20.
//

#ifndef LEARN_LOWDIAGONAL_MATRIX_H
#define LEARN_LOWDIAGONAL_MATRIX_H

#include <iostream>
#include <sstream>
#include "../exception/my_exception.h"

template<class T>
class LowdiagonalMatrix {
public:
    explicit LowdiagonalMatrix(int size) {
        num = size;
        int total = (size*(size+1)) / 2;
        element = new T[total];
        for (int i = 0; i < total; ++i)
            element[i] = 0;
    }

    T& retrieve(int row, int col) {
        checkIndex(row, col);
        if (col > row) return *new T();
        int index = (col * (num * 2 - col + 1)) / 2; //计算当前列之前的所有列的数字个数之和
        index += (row - col); //加上寻找元素在当前有效列的位置
        return element[index];
    }
    T& get(int row, int col) { return retrieve(row, col); }

    void store(int row, int col, T& value) {
        checkIndex(row, col);
        if (col > row) return;
        int index = (col * (num * 2 - col + 1)) / 2; //计算当前列之前的所有列的数字个数之和
        index += row - col; //加上寻找元素在当前有效列的位置
        element[index] = value;
    }

    void output() {
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
private:
    T *element;
    int num;

    void checkIndex(int row, int col) {
        if (row < 0 || row > num || col < 0 || col > num) {
            ostringstream s;
            s << "输入的行列数有误，row=" << row << "，col=" << col << "，最大值不应超过" << num;
            throw new IllegalIndex(s.str());
        }
    }
};
#endif //LEARN_LOWDIAGONAL_MATRIX_H
