//
// Created by samson on 17-12-6.
//

#ifndef LEARN_HASH_TABLE_H
#define LEARN_HASH_TABLE_H

#include <cwctype>
#include "../exception/my_exception.h"

template <class T>
struct Pair {
    int key;
    T value;

    Pair(int k, const T& v) {
        key = k;
        value = v;
    }
};

template <class T>
class LinearHashTable {
public:
    explicit LinearHashTable(int div = 916) {
        size = 0;
        D = div;
        table = new Pair<T>* [div];
        for (int i = 0; i < div; ++i)
            table[i] = nullptr;
    }

    int search(const int& key) {
        int index = key % D;
        int j = index;
        do {
            if (table[j] == nullptr || table[j]->key == key) return j;
            j = (j + 1) % D;
        } while (j != index);

        return j;
    }

    Pair<T>* find(const int& key) {
        int index = search(key);

        if (table[index] == nullptr || table[index]->key != key) return nullptr;

        return table[index];
    }

    void insert(const int& key, const T& value) {
        int index = search(key);

        if (table[index] == nullptr) {
            auto *in = new Pair<T>(key, value);
            table[index] = in;
            size++;
        } else {
            if (table[index]->key == key)
                table[index]->value = value;
            else
                throw Full("table 已经满了");
        }
    }
private:
    Pair<T>** table;
    int size;
    int D;
};

template <class T>
class LinkedHashTable {
public:
    explicit LinkedHashTable(int div = 916) {
        D = div;
        size = 0;
        table = new ArrayList<Pair<T>>* [div];
        for (int i = 0; i < div; ++i)
            table[i] = nullptr;
    }

    void insert(const int& key, const T& value) {
        int index = key % D;
        Pair<T> p(key, value);
        table[index]->append(p);
        size++;
    }

    Pair<T>* find(const int& key) {
        int index = key % D;
        for (int i = 0; i < table[index]->getLength(); ++i) {
            if (table[index]->get(i).key == key)
                return &table[index]->get(i);
        }

        return nullptr;
    }

private:
    ArrayList<Pair<T>>** table;
    int D;
    int size;
};
#endif //LEARN_HASH_TABLE_H
