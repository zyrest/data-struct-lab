//
// Created by samson on 17-11-20.
//

#ifndef LEARN_LOWDIAGONAL_MATRIX_H
#define LEARN_LOWDIAGONAL_MATRIX_H

#include <ctime>
#include <sstream>
#include "../exception/my_exception.h"

template<class T>
class LowdiagonalMatrix {
public:
    explicit LowdiagonalMatrix(int size) {
        num = size;
        element = new T[size*(size-1) / 2];
    }

    T& retrieve(int row, int col) {
        checkIndex(row, col);
        if (col > row) return *new T();

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
