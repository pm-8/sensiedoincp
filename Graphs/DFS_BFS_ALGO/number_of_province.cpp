#include <bits/stdc++.h>
class Solution {
  public:
    void DFSRec(vector<vector<int>>& adj,vector<bool>& visited, int s){
    visited[s] = true;
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> arr(V+1);
        vector<bool> visited(V+1, false);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1){
                    arr[i+1].push_back(j+1);
                    arr[j+1].push_back(i+1);
                }
            }
        }
        int c = 0;
        for(int i = 1; i < V+1; i++){
            if(visited[i] == false){
                c++;
                DFSRec(arr,visited,i);
            }
        }
        return c;
    }
};