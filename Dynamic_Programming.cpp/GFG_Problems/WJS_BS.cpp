// C++ program to implement 
// Weighted Job Scheduling 
#include <bits/stdc++.h>
using namespace std;

// Function to find the closest next job.
int findNextJob(int i, vector<vector<int>> &jobs) {
    int end = jobs[i][1];
    int ans = jobs.size();
    int s = i + 1, e = jobs.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (jobs[mid][0] >= end) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

// Function to find the maximum profit
// from weighted job scheduling
int maxProfit(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    // create a dp table
    vector<int> dp(n);
    
    // iterate over all the jobs
    for(int i = n-1; i >= 0; i--) {
        dp[i] = jobs[i][2];
        
        // find the index of next job
        int next = findNextJob(i, jobs);
        cout << "NEXT IS :-" << next << endl;
        // if next job exists
        if(next < n) {
            dp[i] += dp[next];
        }
        
        // store the maximum profit
        if(i < n-1)
            dp[i] = max(dp[i], dp[i+1]);
    }

    return dp[0];
}

int main() {
    vector<vector<int>> jobs = {
        {1, 2, 50}, 
        {3, 5, 20}, 
        {6, 19, 100}, 
        {2, 100, 200}
    };
    cout << maxProfit(jobs);
    return 0;
}