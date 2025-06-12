//O(N^N) recursive approach---->>>
//sort the jobs in ascending order based on their START TIME
//maxProfits(i,jobs) = max(maxProfit(j,jobs)), where i < j < n
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int maxProfitRecur(vector<vector<int>>& jobs, int i, int last){
    if(i == jobs.size()) return 0;
    int ans = maxProfitRecur(jobs, i + 1, last);
    if(jobs[i][0] >= last){
        ans = max(ans, jobs[i][2] + maxProfitRecur(jobs,i+1,jobs[i][1]));
    }
    return ans;
}
int maxProfitTable(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    // create a dp table
    vector<int> dp(n);

    // stores the maximum profit
    int res = 0;
    
    // iterate over all the jobs
    for(int i = n-1; i >= 0; i--) {
        dp[i] = jobs[i][2];
        
        // find the maximum profit
        for(int j = i+1; j < n; j++) {
            if(jobs[i][1] <= jobs[j][0]) {
                dp[i] = max(dp[i], dp[j] + jobs[i][2]);
            }
        }
        
        res = max(res, dp[i]);
    }

    return res;
}
int maxProfit(vector<vector<int>>& jobs){
    int n = jobs.size();
    sort(jobs.begin(), jobs.end());
    return maxProfitTable(jobs);
}
int main() {
    vector<vector<int>> jobs = {
        {1, 2, 50}, 
        {3, 5, 20}, 
        {6, 19, 100}, 
        {2, 100, 200}
    };
    cout << maxProfit(jobs) << endl;
    return 0;
}
