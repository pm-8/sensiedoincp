//Two pointers method
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5;
vector<int> gr[N];
int dep[N],parent[N];
void dfs(int cur, int par){
    parent[cur] = par;
    dep[cur] = dep[par] + 1;
    for(auto x : gr[cur]){
        if(x != par){
            dfs(x,cur);
        }
    }
}
int LCA(int u, int v){
    if(u==v) return u;
    //depth of u is more than depth of v
    if(dep[v] > dep[u]) swap(u,v);
    int diff = dep[u] - dep[v];
    while(diff--){
        u = parent[u];
    }
    while(u!=v){
        u = parent[v];
        v = parent[u];
    }

    return u;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++){
        cout << 1 << " " << dep[i] << "\n";
    }
    return 0;
}