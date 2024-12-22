//LCA with binary lifitng

//Two pointers method
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5, M = 20;
vector<int> gr[N];
int dep[N],parent[N][M];
void dfs(int cur, int par){
    parent[cur][0] = par;
    for(int j = 1; j < M; j++){
        parent[cur][j] = parent[parent[cur][j-1]][j-1];

    }
    dep[cur] = dep[par] + 1;
    for(auto x : gr[cur]){
        if(x != par){
            dfs(x,cur);
        }
    }
}
int LCA(int u, int v){
    if(u==v) return u;
    if(dep[u] < dep[v]) swap(u,v);
    int diff = dep[u] - dep[v];
    for(int j = M-1;  j >= 0; j--){
        if((diff >> j) & 1){
            u = parent[u][j];
        }
    }
    //u and v are on the same level
    for(int j = M-1; j >= 0; j--){
        if(parent[u][j] != parent[v][j]){
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
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
    for(int i = 0; i <= 12; i++) 
    return 0;
}