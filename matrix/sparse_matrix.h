//
// Created by samson on 17-11-22.
//

#ifndef LEARN_SPARSE_MATRIX_H
#define LEARN_SPARSE_MATRIX_H

#include "../list/array_list.h"
#include "../list/array_list.h"
using namespace std;

template <class T>
struct SparseTerm {
    int row, col;
    T value;
    SparseTerm(int r, int c, T &v) {
        row = r;
        col = c;
        value = v;
    }
    SparseTerm() = default;

    bool operator==(SparseTerm<T> b) {
        return row == b.row && col==b.col && value==b.value;
    }

};

template <class T>
class SparseMatrix {
public:
    SparseMatrix(int r, int c) {
        row = r;
        col = c;
        terms = new ArrayList< SparseTerm<T> >(100);
    }

    void add(SparseMatrix<T> &b) {
        if (row != b.row || col != b.col) throw IllegalInput("两者行列不同");

        int aIndex = 0, bIndex = 0;
        auto *ans = new ArrayList< SparseTerm<T> > (terms->getLength() + b.terms->getLength());
        while (aIndex < terms->getLength() && bIndex < b.terms->getLength()) {
            SparseTerm<T> aTerm = terms->get(aIndex);
            SparseTerm<T> bTerm = b.terms->get(bIndex);

            if (aTerm.row < bTerm.row) {
                ans->append(aTerm);
                aIndex++;
                continue;
            } else if (bTerm.row < aTerm.row) {
                ans->append(bTerm);
                bIndex++;
                continue;
            } else {
                if (aTerm.col < bTerm.col) {
                    ans->append(aTerm);
                    aIndex++;
                    continue;
                } else if (aTerm.col > bTerm.col) {
                    ans->append(bTerm);
                    bIndex++;
                    continue;
                } else {
                    bTerm.value += aTerm.value;
                    ans->append(bTerm);
                    aIndex++;
                    bIndex++;
                }
            }
        }

        terms = ans;
    }

    void transpose() {
        for (int i = 0; i < terms->getLength(); ++i) {
            int max = terms->get(i).col;
            int maxIndex = i;
            for (int j = i; j < terms->getLength(); ++j) {
                if (terms->get(j).col > max) maxIndex = j;
            }
            int rowBack = terms->get(i).row;
            int colBack = terms->get(i).col;
            T vBack = terms->get(i).value;

            terms->get(i).row = terms->get(maxIndex).row;
            terms->get(i).col = terms->get(maxIndex).col;
            terms->get(i).value = terms->get(maxIndex).value;

            terms->get(maxIndex).row = rowBack;
            terms->get(maxIndex).col = colBack;
            terms->get(maxIndex).value = vBack;

            int cBack = terms->get(i).col;
            terms->get(i).col = terms->get(i).row;
            terms->get(i).row = cBack;
        }

        int tmp = row;
        row = col;
        col = tmp;
    }

    T& get(int row, int col) {
        checkIndex(row, col);

        int index = -1;
        for (int i = 0; i < terms->getLength(); ++i) {
            if (row != terms->get(i).row) continue;
            else if (col != terms->get(i).col) continue;
            else {
                index = i;
                break;
            }
        }
        if (index != -1) return terms->get(index).value;
        else return *new T();
    }

    void store(int row, int col, T &value) {
        checkIndex(row, col);

        SparseTerm<T> insert(row, col, value);
        int x = 0;
        for (; x < terms->getLength(); ++x) {
            if (terms->get(x).row >= row) break;
        }
        int y = x;
        for (; y < terms->getLength(); ++y) {
            if (terms->get(y).col >= col) break;
        }
        terms->insert(y, insert);
    }

    void output() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }

private:
    ArrayList< SparseTerm<T> > *terms;
    int row, col;

    void checkIndex(int r, int c) {
        if (r < 0 || r > row || r < 0 || r > col) {
            ostringstream s;
            s << "输入的行列数有误，row=" << r << "，最大值不应超过" << row << "，col=" << c << "，最大值不应超过" << col;
            throw new IllegalIndex(s.str());
        }
    }
};
#endif //LEARN_SPARSE_MATRIX_H
