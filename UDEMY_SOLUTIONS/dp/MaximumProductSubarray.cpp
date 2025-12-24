#include<bits/stdc++.h>
using namespace std;
/*
2 3 -2 4 -2
*/
int maxProduct(vector<int> nums) {
    int curMax = 1, curMin = 1;
        int res = nums[0];
        
        for(int i : nums){
            // Store the calculation in a temp variable first
            int tempMax = max(i, max(i * curMax, i * curMin));
            
            // Now calculate curMin using the OLD curMax
            curMin = min(i, min(i * curMax, i * curMin));
            
            // Update curMax to the new value
            curMax = tempMax;
            
            res = max(res, curMax);
        }
        return res;
}