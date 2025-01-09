#include<bits/stdc++.h>
#define N 10000
using namespace std;
int main(){
    int n,sum;
    cin >> n >> sum;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> memo(n+1,vector<int>(sum+1,-1));
    function<bool(int,int)> isSubset = [&](int i, int s){
        //if the sum is zero, there is a subset
        if(s == 0) return 1;
        //if no elements left, then for sure it's fucked up
        if(i <= 0) return 0;
        if(memo[i][s] != -1) return memo[i][s];
        if(arr[i] > sum) memo[i][s] = isSubset(i-1,s);
        else memo[i][s] = isSubset(i-1,s - arr[i-1]);
    };
    cout << (bool)isSubset(n,sum) << endl;
}