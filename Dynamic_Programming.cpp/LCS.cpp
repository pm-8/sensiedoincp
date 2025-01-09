#include <bits/stdc++.h>
using namespace std;

string s, t;
string res = "";
int n, m;
vector<vector<int>> dp;

int give_lcs(int i, int j) {
    if (i == n || j == m) return 0; 
    if (dp[i][j] != -1) return dp[i][j]; 
    
    if (s[i] == t[j])
        dp[i][j] = give_lcs(i + 1, j + 1) + 1; 
    else
        dp[i][j] = max(give_lcs(i + 1, j), give_lcs(i, j + 1)); 
    
    return dp[i][j];
}

void trace_back(int i, int j) {
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            res += s[i]; 
            i++;
            j++;
        } else if (give_lcs(i + 1, j) == give_lcs(i, j)) {
            i++; 
        } else {
            j++; 
        }
    }
}

int main() {
    cin >> s >> t;
    n = s.size();
    m = t.size();
    dp.assign(n + 1, vector<int>(m + 1, -1)); 
    
    give_lcs(0, 0); 
    trace_back(0, 0); 
    
    cout << res << endl; 
    return 0;
}
