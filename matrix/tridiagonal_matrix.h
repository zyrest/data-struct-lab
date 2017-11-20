//
// Created by samson on 17-11-20.
//

#ifndef LEARN_TRIDIAGONAL_MATRIX_H
#define LEARN_TRIDIAGONAL_MATRIX_H

#include <sstream>
#include "../exception/my_exception.h"
using namespace std;

template<class T>
class TridiagonalMatrix {
public:
    explicit TridiagonalMatrix(int size) {
        num = size;
        element = new T[(size-2)*3 + 4];
    }

    T& retrieve(int row, int col) {
        checkIndex(row, col);
        int sub = row - col;
        switch(sub) {
            case -1 :
                return element[col*3 - 1];
            case 0 :
                return element[col*3];
            case 1 :
                return element[col*3 + 1];
            default:
                return *new T();
        }
    }
    T& get(int row, int col) { return retrieve(row, col); }

    void store(int row, int col, T &value) {
        checkIndex(row, col);

        int sub = row - col;
        int index = -1;
        switch(sub) {
            case -1 :
                index = col*3 - 1;
                break;
            case 0 :
                index = col*3;
                break;
            case 1 :
                index = col*3 + 1;
                break;
            default:
                index = -1;
        }
        if (index == -1) return;
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

#endif //LEARN_TRIDIAGONAL_MATRIX_H
