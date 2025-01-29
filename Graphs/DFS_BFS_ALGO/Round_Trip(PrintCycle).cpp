#include <bits/stdc++.h>
#define int long long
#define INF 1000000007
#define N 200005 
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adjg[n + 1]; 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjg[u].push_back(v);
        adjg[v].push_back(u);
    }
    
    vector<int> cycle;
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    function<void(int)> dfs = [&](int node) {
        vis[node] = true;
        for (int i : adjg[node]) {
            if (!vis[i]) {
                parent[i] = node;
                dfs(i);
                if (!cycle.empty()) return; 
            } else if (i != parent[node] && cycle.empty()) {
                int cur = node;
                cycle.push_back(i); 
                while (cur != i) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(i);
                return;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
        if (!cycle.empty()) break; 
    }

    if (!cycle.empty()) {
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int i : cycle) {
            cout << i << " ";
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
