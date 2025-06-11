//Naive Approach
//O(3^(N*M)) TC
//O(N*M) SC

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string s1, s2;
vector<vector<int>> dp;
int editDistRec(int n, int m){
    if(m == 0) return n;
    if(n == 0) return m;
    int &ans = dp[n][m];
    if(ans != -1) return ans;
    //Case 1: if arr[n] == arr[m] then f(n-1, m-1)
    if(s1[n-1] == s2[m-1]){
        ans = editDistRec(n-1, m-1);
    }
    else{
        ans = 1 + min({editDistRec(n,m-1),editDistRec(n-1,m),editDistRec(n-1,m-1)});
    }
    return ans;
}




int editDistance(string& a, string& b) {
    s1 = a;
    s2 = b;
    dp = vector<vector<int>>(a.size() + 5, vector<int>(b.size() + 5,-1));
    return editDistRec(s1.length(), s2.length());
}

int main() {
    
    string s1,s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2);

    return 0;
}