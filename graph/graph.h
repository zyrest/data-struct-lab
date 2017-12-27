//
// Created by 96428 on 2017/12/23.
//

#ifndef LEARN_GRAPH_H
#define LEARN_GRAPH_H

#include "../list/list.h"
#include "../queue/queue.h"
#include "../stack/stack.h"

struct Edge {
    int i;
    int j;
    int weight;

    Edge() = default;

    Edge(int one, int two) {
        i = one;
        j = two;
        weight = 1;
    }

    Edge(int one, int two, int w) {
        i = one;
        j = two;
        weight = w;
    }

    bool operator== (const Edge &e) const {
        return i == e.i && j == e.j && weight == e.weight;
    }
};

template <class T>
class Graph {
public:
    virtual ~Graph() {};

    virtual int numberOfVertices() const = 0;
    virtual int numberOfEdges() const = 0;
    virtual bool existsEdge(int, int) const = 0;
//    virtual void insertEdge()
//    virtual
//    virtual
//    virtual
//    virtual
};

class LinkedGraph {
public:
    explicit LinkedGraph(int vNum = 0) {
        if (vNum < 0)
            throw IllegalIndex("vNum should be > 0");
        n = vNum;
        e = 0;
        list = new ArrayList<int> [n+1];
    }

    ~LinkedGraph() { delete[] list;}

    bool existEdge(int i, int j) {
        if (i < 0 || j < 0 || i > n || j > n)
            return false;

        return list[i].search(j) != -1;
    }

    void addEdge(Edge& edge) {
        int i = edge.i;
        int j = edge.j;

        if (i < 0 || j < 0 || i > n || j > n)
            throw IllegalIndex("illegal");

        if (list[i].search(j) == -1) {
            list[i].append(j);
            e++;
        }
    }

    void deleteEdge(int i, int j) {
        if (i >= 0 && j >= 0 && i <= n && j <= n) {
            int index = list[i].search(j);
            if (index != -1) {
                list[i].remove(index);
                e--;
            }
        }
    }

    int inDegree(int i) {
        check(i);

        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (list[j].search(i) != -1) sum++;
        }

        return sum;
    }

    int outDegree(int i) {
        check(i);

        return list[i].getLength();
    }

    void bfs(int v, int reach[], int label) {
        ArrayQueue<int> q(n);
        reach[v] = label++;
        q.push(v);

        while (! q.isEmpty() ) {
            int w = q.pop();

            for (int i = 0; i < list[w].getLength(); i++) {
                int num = list[w].get(i);

                if (reach[num] == 0) {
                    q.push(num);
                    reach[num] = label++;
                }
            }
        }
    }

    void dfs(int v, int reach[], int label) {
        ArrayStack<int> s(n);
        reach[v] = label++;
        s.push(v);

        while (! s.isEmpty() ) {
            int w = s.pop();

            for (int i = 0; i < list[w].getLength(); i++) {
                int num = list[w].get(i);

                if (reach[num] == 0) {
                    s.push(num);
                    reach[num] = label++;
                }
            }
        }
    }

    void dfsGTree() {
        int label = 99;
        for (int i = 1; i <= n; ++i) {
            int r[n+1];
            for (int j = 0; j <= n; ++j) r[j] = 0;
            ArrayList<Edge> es(e);

            ArrayStack<int> s(n);
            r[i] = label;
            s.push(i);
            while (! s.isEmpty() ) {
                int w = s.pop();

                for (int k = 0; k < list[w].getLength(); k++) {
                    int num = list[w].get(k);

                    if (r[num] == 0) {
                        Edge e(w, num);
                        es.append(e);

                        s.push(num);
                        r[num] = label;
                    }
                }
            }

            if (es.getLength() == n-1) {
                for (int j = 0; j < n-1; ++j) {
                    Edge e = es.get(j);
                    cout << "{" << e.i << ", " << e.j << "}" << endl;
                }
            }
        }
    }


private:
    int n;
    int e;
    ArrayList<int> *list;

    void check(int i) {
        if (i < 0 || i > n)
            throw IllegalIndex("illegal");
    }
};
#endif //LEARN_GRAPH_H