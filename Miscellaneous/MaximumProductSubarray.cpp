//create 3 variables, currMin, currMax, and maxProd
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //defined all the variables we are going to keep track of
    int currMin, currMax, maxProd;
    currMin = currMax = maxProd = arr[0];
    
    for(int i = 1; i < n; i++){
        //store maximum product at the current index
        int temp = max({arr[i], arr[i] * currMax, currMin * arr[i]});
        //store the minimum product at the current index
        currMin = min({arr[i], arr[i] * currMax, currMin * arr[i]});
        //now change currMax
        currMax = temp;
        maxProd = max(maxProd,currMax);
    }
    cout << maxProd << endl;
    return 0;
}