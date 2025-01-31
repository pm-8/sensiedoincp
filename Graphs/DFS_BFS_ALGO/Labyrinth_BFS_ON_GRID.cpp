#include <bits/stdc++.h>
#define int long long
#define INF 1000000007
#define N 200005 
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    char arr[n][m];
    char ch[n][m];
    char c[] = {'U','L','D','R'};
    // char rc[] = {'D','R','U','L'};
    int dist[n][m];
    memset(dist,0,sizeof(dist));
    memset(ch, '#', sizeof(ch));
    pair<int,int> st;
    pair<int,int> end;
    bool vis[n][m];
    pair<int,int> par[n][m];
    int x[] = {-1,0,1,0};
    int y[] = {0,-1,0,1};
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '#') vis[i][j] = true;
            if(arr[i][j] == 'A') st = make_pair(i,j);
            if(arr[i][j] == 'B') end = make_pair(i,j);
        }
    }
    // cout << end.first << " " << end.second << endl;
    queue<pair<int,int>> q;
    q.push(st);
    pair<int,int> P;
    while(!q.empty()){
        P = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int f = P.first + x[i];
            int s = P.second + y[i];
            if(f >= 0 && f < n && s >= 0 && s < m && !vis[f][s]){
                q.push(make_pair(f,s));
                vis[f][s] = true;
                ch[f][s] = c[i];
                dist[f][s] = dist[P.first][P.second] + 1;
            }
        }
    }
    string ans = "";
    int d = dist[end.first][end.second];
    P = make_pair(end.first,end.second);
    for(int i = d; i > 0; i--){
        char cc= ch[P.first][P.second];
        if(cc == 'U'){
            P.first += 1;
        }
        if(cc == 'R'){
            P.second -= 1;
        }
        if(cc == 'L'){
            P.second += 1;
        }
        if(cc == 'D'){
            P.first -= 1;
        }
        ans += cc;
    }
    reverse(ans.begin(),ans.end());
    if(d == 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << d << endl;
    cout << ans << endl;
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
