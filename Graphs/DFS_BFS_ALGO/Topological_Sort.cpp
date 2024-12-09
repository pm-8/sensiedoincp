/*
for i to n
if node not visited
dfs
push back the node to the stack
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
   void dfs(stack<int>& s, vector<int>& vis, vector<vector<int>>& adj, int node) {
        vis[node] = 1;
        for (int adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(s, vis, adj, adjNode);
            }
        }
        s.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        stack<int> s;
        vector<int> vis(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(s, vis, adj, i);
            }
        }
        
        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends