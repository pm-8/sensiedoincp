#include <bits/stdc++.h>
using namespace std;
int tiling(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 3;
    return tiling(n-2) + tiling(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << tiling(n) << endl;
    return 0;
}