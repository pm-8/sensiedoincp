#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve() {
    vector<int> nums1, nums2;
    int n, m;
    cin >> n;
    nums1.resize(n);
    for (int &x : nums1) cin >> x;

    cin >> m;
    nums2.resize(m);
    for (int &x : nums2) cin >> x;

    stack<int> st;
    unordered_map<int, int> num;
    vector<int> ans(n);

    for (int i = m - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        num[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    for (int i = 0; i < n; i++) {
        ans[i] = num[nums1[i]];
    }

    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) 
        solve();
    
    return 0;
}
