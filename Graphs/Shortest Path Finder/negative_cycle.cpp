#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
struct Edge{
    int a,b,cost;
};
int n,m;
vector<Edge> edges;
const int INF = 1e8;
void solve() {
    cin >> n >> m;
    vector<int> dist(n+1,INF);
    vector<int> p(n+1,-1);
    edges.resize(m);
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges[i].a = u;
        edges[i].b = v;
        edges[i].cost = w;
        // cout << edges[i].a << " " << edges[i].b << endl;
    }
    dist[1] = 0;
    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(Edge e : edges){
            if(dist[e.a] != INF && dist[e.b] > dist[e.a]+e.cost){
                dist[e.b] = max(-INF,dist[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
    if(x == -1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            x = p[x];
        }
        vector<int> cycle;
        for(int v = x; ; v = p[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        // cout << "Negative Cycle: ";
        for(int v : cycle){
            cout << v << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}