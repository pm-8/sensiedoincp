/*
The idea is to iterate of every index j of b[] for every index i in a[]. 
We use a linear array dp of length n intialized with zero to keep track of the LCIS ending on jth index of b[].  
We also use a variable currentLength to store the length of the LCIS for the current element of a[]. 
This variable helps to keep track of the LCIS ending at the previous index of a[] but not including the current element in a[].

If a[i] is equal to b[j], then found a potential element of the LCIS that ends at b[j]. 
At this point, we can update dp[j] to be the maximum of its current value and currentLength + 1. 
This is because currentLength keeps track of the longest LCIS that ends at a previous index in a[].

If a[i] > b[j], it means that b[j] can be part of an increasing subsequence that ends with a[i]. 
Hence, we need to update the currentLength to be the maximum value between currentLength and dp[j]. 
This ensures that currentLength holds the length of the longest subsequence ending at any previous element b[k] (where k < j).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LCIS(vector<int>& a, vector<int>& b){
    int m = a.size();
    int n = b.size();
    vector<int> dp(n,0);
    for(int i = 0; i < m; i++){
        int currentLength = 0;
        for(int j = 0; j < n; j++){
            if(a[i] == b[j]){
                dp[j] = max(dp[j],currentLength + 1);
            }
            else if(a[i] > b[j]){
                currentLength = max(currentLength,dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main() {
    vector<int> a = {3, 4, 9, 1 };
    vector<int> b = {5, 3, 8, 9, 10, 2, 1};
    cout << LCIS(a, b);
    return 0;
}