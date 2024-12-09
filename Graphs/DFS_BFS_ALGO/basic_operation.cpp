#include <bits/stdc++.h>
using namespace std;
void DFSRec(vector<vector<int>>& adj,vector<bool>& visited, int s){
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}
void DFS(vector<vector<int>> & adj, int s){
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}
void addEdge(vector<pair<int,int>> adj[],int u, int v, int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void printWeightedGraph(vector<pair<int,int>> adj[], int V){
    int v,w;
    for(int u = 0; u < V; u++){
        cout << "Node" << u << " makes an edge with \n";
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            v = it -> first;
            w = it -> second;
            cout << "\tNode " << v << " with edge weight =" << w << "\n";
        }
        cout << "\n";
    }
}
void addUndirectedEdges(vector<vector<int>>& v, int i, int j){
    v[i].push_back(j);
    v[j].push_back(i);
}
void addDirectedEdges(vector<vector<int>>& v,int i, int j){
    v[i].push_back(j);
}
void displayList_Graph(const vector<vector<int>>& adj){
    for(int i = 0; i < adj.size(); i++){
        cout << i << ":";
        for(int j : adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{   int V = 4; 
    vector<vector<int>> adjacentList(V);
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 10);
    // addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    // addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addUndirectedEdges(adjacentList,0,1);
    addUndirectedEdges(adjacentList,0,2);
    addUndirectedEdges(adjacentList,1,2);
    addUndirectedEdges(adjacentList,2,3);
    cout << "Adjacency List Representation:" << endl;
    displayList_Graph(adjacentList);
    cout << "Adjacency Weighted Graph Representation: " << endl;
    printWeightedGraph(adj, V);
    DFS(adjacentList, 0);
    return 0;
}