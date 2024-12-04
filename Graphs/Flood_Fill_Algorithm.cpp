//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        int s = image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = -1; i <= 1; i+=1){
                    int nr = row + i;
                    int nc = col;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && image[nr][nc] == s){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                        image[nr][nc] = newColor;
                }
            }
            for(int i = -1; i <= 1; i+=1){
                    int nr = row;
                    int nc = col+i;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && image[nr][nc] == s){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                        image[nr][nc] = newColor;
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends