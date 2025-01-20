#include <bits/stdc++.h>
#define int long long
using namespace std;

// Union-Find (Disjoint Set Union) structure
struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
            return true; // Union performed
        }
        return false; // Already in the same set
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    UnionFind ufF(n), ufG(n);

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ufF.unionSets(u, v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ufG.unionSets(u, v);
    }

    vector<pair<int, int>> operations;

    map<int, vector<int>> componentsG;
    for (int i = 0; i < n; i++) {
        componentsG[ufG.find(i)].push_back(i);
    }

    for (auto &[gRoot, gNodes] : componentsG) {
        set<int> fRoots;
        for (int node : gNodes) {
            fRoots.insert(ufF.find(node));
        }

        vector<int> fRootsList(fRoots.begin(), fRoots.end());
        if (fRootsList.size() > 1) {
            int primaryRoot = fRootsList[0];
            for (size_t i = 1; i < fRootsList.size(); i++) {
                int currentRoot = fRootsList[i];
                int u = -1, v = -1;
                for (int node : gNodes) {
                    if (ufF.find(node) == primaryRoot) u = node;
                    if (ufF.find(node) == currentRoot) v = node;
                }
                if (u != -1 && v != -1) {
                    operations.push_back({u, v});
                    ufF.unionSets(u, v);
                }
            }
        }
    }

    cout << operations.size() << "\n";
    for (auto &[u, v] : operations) {
        cout << u + 1 << " " << v + 1 << "\n"; // Convert back to 1-based index
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
