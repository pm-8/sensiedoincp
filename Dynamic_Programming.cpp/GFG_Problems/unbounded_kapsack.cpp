//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
        for(int i = 0; i <= capacity; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= capacity; j++){
                if(j-wt[i-1] >= 0)
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][capacity];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends