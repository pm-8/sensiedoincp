#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (T &x : vec) in >> x;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        out << vec[i] << (i + 1 < vec.size() ? ' ' : '\n');
    }
    return out;
}
int partition(vector<int>& arr, int s, int e){
    int i = s - 1;
    int pivot = arr[e];
    for(int j = s; j < e; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
int quickselect(vector<int>& arr, int s, int e, int k){
    int p = partition(arr,s,e);
    if(p==k){
        return arr[p];
    }
    else if(k < p){
        return quickselect(arr,s,p-1,k);
    }
    else{
        return quickselect(arr,p+1,e,k);
    }
}
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    cin >> v;
    int x = quickselect(v,0,n-1,2);
    cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)