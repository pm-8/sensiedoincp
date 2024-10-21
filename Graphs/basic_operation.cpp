#include<iostream>
#include <vector>
using namespace std;
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
    addUndirectedEdges(adjacentList,0,1);
    addUndirectedEdges(adjacentList,0,2);
    addUndirectedEdges(adjacentList,1,2);
    addUndirectedEdges(adjacentList,2,3);
    cout << "Adjacency List Representation:" << endl;
    displayList_Graph(adjacentList);
    return 0;
}