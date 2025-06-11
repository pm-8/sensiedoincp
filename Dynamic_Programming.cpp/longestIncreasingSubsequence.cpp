//Longest Increasing Subsequence (UDEMY)


// Let L(i) be the length of the LIS ending at index i

// arr[i] is the last element 

// L(i) = 1 + max(L(prev)) if arr[prev] < arr[i]

// L(i) = 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int n;
vector<int> dp;
int dfs(int i) {
    // if (i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = i - 1; j >= 0; j--) {
        if (arr[i] > arr[j]) {
            ans = max(ans, 1 + dfs(j));
        }
    }
    return dp[i] = ans;
}

int lis(vector<int>& A) {
    arr = A;
    n = A.size();
    dp = vector<int>(n,-1);
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dfs(i));
    }
    return res;
}
int main()
{   

    return 0;
}