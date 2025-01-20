#include<bits/stdc++.h>
#define int long long int
#define N 10000
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    int count = 0;
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int c = (int)(i ^ j);
            if(c > n) continue;
            if((i+j>c) && (i+c>j) && (c+j>i) && (mp[i] == 0 || mp[j] == 0 || mp[c] == 0)){
                mp[i]=1;
                mp[j]=1;
                mp[c]=1;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}