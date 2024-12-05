/*
// inside int main()
queue<int> q; q.push(s);
vi color(V, INF); color[s] = 0;
bool isBipartite = true; // addition of one boolean flag, initially true
while (!q.empty() & isBipartite) { // similar to the original BFS routine
int u = q.front(); q.pop();
for (int j = 0; j < (int)AdjList[u].size(); j++) {
ii v = AdjList[u][j];
if (color[v.first] == INF) { // but, instead of recording distance,
color[v.first] = 1 - color[u]; // we just record two colors {0, 1}
q.push(v.first); }
else if (color[v.first] == color[u]) { // u & v.first has same color
isBipartite = false; break; } } } // we have a coloring conflict
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> color(n,-1);
        queue<int> q;
        color[0] = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(color[it]!=-1){
                    if(color[it] == color[node]) return false;
                    continue;
                }
                if(color[node] == 0)color[it] = 1;
                else color[it] = 0;
                q.push(it);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends