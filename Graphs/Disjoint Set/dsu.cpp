#include <bits/stdc++.h>
#define int long long
#define INF 1000000007
#define N 200005 
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // cout << "HEY" << endl
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++){
        v.push_back({g[i].size(),i});
        // cout << g[i].size() << " " << i << endl;
    }
    // cout << endl;
    for(int i : g[5]){
        cout << i << endl;
    }
    // sort(v.rbegin(),v.rend());
    // vector<int> vis(n+1,-1);
    // int a = v[0].second;
    // int b;
    // if(v[1].first == v[2].first) b = v[2].second;
    // else
    // b = v[1].second;
    // // cout << a << b << v[2].second <<  endl;
    // vis[a] = vis[b] = 1;
    // function<void(int)> dfs = [&](int i){
    //     vis[i] = 1;
    //     for(int adjNode : g[i]){
    //         if(vis[adjNode] == -1){
    //             dfs(adjNode);
    //         }
    //     }
    // };
    // int c = 0;
    // for(int i = 1; i <= n; i++){
    //     if(vis[i] != -1) continue;
    //     dfs(i);
    //     c++;
    // }
    // cout << c << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("opp.txt", "w", stdout);
// #endif

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
