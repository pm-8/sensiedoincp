//GFG Problem :- Largest Divisible Subset

//Naive Solution :- O(2^N)
// C++ Implementation for Largest Divisible Subset
// using Recursion
#include <bits/stdc++.h>
using namespace std;

vector<int> LargestSubset(vector<int>& arr) {
    
}


int main() {

    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> res = LargestSubset(arr); 
  
    for (int num : res) {
        cout << num << " ";
    } 
    
    return 0;
}