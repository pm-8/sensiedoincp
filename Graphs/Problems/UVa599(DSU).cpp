#include <bits/stdc++.h>
#define int long long
#define N 100
using namespace std;

// DSU Helper Functions
int findSet(int u, vector<int>& parent) {
    if (u == parent[u]) return u;
    return parent[u] = findSet(parent[u], parent); // Path compression
}

void unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) swap(rootU, rootV);
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }
}

// DFS for Cycle Detection
bool hasCycleDFS(int u, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycleDFS(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

void solve() {
    string s;
    vector<int> adj[N];
    vector<pair<int, int>> edgL;

    // Read edges until '*' is encountered
    while (true) {
        cin >> s;
        if (s[0] == '*') break;
        char u = s[1], v = s[3];
        adj[u - 'A'].push_back(v - 'A');
        adj[v - 'A'].push_back(u - 'A');
        edgL.push_back(make_pair(u - 'A', v - 'A'));
    }

    // Read nodes and count them
    string nodes;
    cin >> nodes;
    vector<bool> present(N, false);
    int n = 0;
    for (char c : nodes) {
        if (c != ',') {
            present[c - 'A'] = true;
            n++;
        }
    }
    vector<int> parent(N), size(N, 1);
    for (int i = 0; i < N; i++) parent[i] = i;

    // Process edges and update DSU
    for (int i = 0; i < edgL.size(); i++) {
        int u = edgL[i].first, v = edgL[i].second;
        unionBySize(u, v, parent, size);
    }

    // Update parent array for accurate connected components
    for (int i = 0; i < N; i++) {
        if (present[i]) {
            findSet(i, parent);
        }
    }

    // Count trees and acorns
    map<int, int> componentSize;
    for (int i = 0; i < N; i++) {
        if (present[i]) {
            int root = parent[i];
            if (componentSize.find(root) == componentSize.end()) {
                componentSize[root] = 0;
            }
            componentSize[root]++;
        }
    }

    int acorns = 0, trees = 0;

    for (const auto& [node, size] : componentSize) {
    if (size == 1) {
        acorns++; // Single node (acorn)
        continue;
    }

    // Check for cycles using adjacency list
    vector<bool> visited(N, false);
    if (!hasCycleDFS(node, -1, adj, visited)) {
        trees++; // Component is a tree if no cycles
    }
}


    cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
