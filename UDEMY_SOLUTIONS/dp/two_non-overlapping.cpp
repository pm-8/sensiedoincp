/*
Initial: l=0, sum=0, minLen=∞, result=∞
dp = [∞, ∞, ∞, ∞, ∞]

r=0: arr[0]=3
  sum = 3
  sum == target ✓
  currLen = 0-0+1 = 1
  l=0, so no previous subarray
  minLen = min(∞, 1) = 1
  dp[0] = 1
  
r=1: arr[1]=2
  sum = 3+2 = 5
  while(5 > 3): sum -= arr[0]=3, l=1, sum=2
  sum != target
  dp[1] = 1 (carry forward minLen)
  
r=2: arr[2]=2
  sum = 2+2 = 4
  while(4 > 3): sum -= arr[1]=2, l=2, sum=2
  sum != target
  dp[2] = 1
  
r=3: arr[3]=4
  sum = 2+4 = 6
  while(6 > 3): sum -= arr[2]=2, l=3, sum=4
  while(4 > 3): sum -= arr[3]=4, l=4, sum=0
  sum != target
  dp[3] = 1
  
r=4: arr[4]=3
  sum = 0+3 = 3
  sum == target ✓
  currLen = 4-4+1 = 1
  l=4, check dp[3] = 1 ✓
  result = min(∞, 1+1) = 2  ← Found answer!
  minLen = min(1, 1) = 1
  dp[4] = 1
*/

#include<bits/stdc++.h>
using namespace std;

int minSumOfLengths(vector<int> arr, int target) {
    int n = arr.size();
    vector<int> minLen(n,INT_MAX);
    int l = 0, sum = 0;
    int minSoFar = INT_MAX;
    int res = INT_MAX;
    for(int r = 0; r < n; r++){
        sum += arr[r];
        while(sum > target){
            sum -= arr[l];
            l++;
        }
        if(sum == target){
            int currLen = r - l + 1;
            if(l > 0 && minLen[l-1] != INT_MAX){
                res = min(res,currLen + minLen[l-1]);
            }
            minSoFar = min(minSoFar, currLen);
        }
        minLen[r] = minSoFar;
    }
    return res == INT_MAX ? -1 : res;
}