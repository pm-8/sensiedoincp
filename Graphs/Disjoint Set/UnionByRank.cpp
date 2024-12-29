#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        l.push_back(make_pair(u, v));
    } 

    // FIND
    int findSet(int i, int parent[]) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = findSet(parent[i], parent);
    }

    // UNION
    void union_set(int x, int y, int parent[], int rank[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }

    bool contains_cycle() {
        int* parent = new int[V];
        int* rank = new int[V];

        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 0;
        }

        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2) {
                union_set(s1, s2, parent, rank);
            } else {
                cout << "Cycle detected between vertices: " << i << " and " << j << endl;
                delete[] rank;
                delete[] parent;
                return true;
            }
        }

        delete[] rank;
        delete[] parent;
        return false;
    }
};

int main() {
    Graph g(7); // Update graph size to accommodate vertices 0 to 6
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << g.contains_cycle() << endl;

    return 0;
}
