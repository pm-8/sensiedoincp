#include <bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
void solve() {
    int n,w;
    cin >> n >> w;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    int maxCost = INT_MIN;
    function<void(int,int,int)> dfs = [&](int i, int wE, int cost){
        if(wE > w){
            return;
        }
        if(i == n) {maxCost = max(maxCost,cost);return;}
        
        dfs(i+1,wE,cost);
        dfs(i+1,wE+v[i].first,cost + v[i].second);
    };
    dfs(0,0,0);
    cout << maxCost << endl;
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
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
