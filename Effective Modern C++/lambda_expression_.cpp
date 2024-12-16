#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxN = 1e5+1;
void solve() {
    int N {5};
    int adj[N] {2,3,4,5,6};
    for_each(adj, adj+N,[](int i){
        if(!(i&1)) cout << i << endl; 
    }
    );
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("opp.txt", "w", stdout);
// #endif
    // int t;
    // cin >> t;
    // while(t--)
        solve();
    
}