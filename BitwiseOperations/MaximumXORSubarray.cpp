#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define dd long double
#define MOD 1000000000000000
struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        child[0] = child[1] = nullptr;
    }
};
void insert(TrieNode* root, int n){
    TrieNode* node = root;
    for(int i = 63; i >= 0; i--){
        int bit = (n >> i) & 1;
        if(!node -> child[bit])
            node->child[bit] = new TrieNode();
        node = node -> child[bit];
    }
}
int query(TrieNode* root, int n){
    TrieNode* node = root;
    int maxOr = 0ll;
    for(int i = 63; i >= 0; i--){
        int bit = ((n >> i) & 1);
        if(node -> child[1-bit]){
            maxOr |= (1ll << i);
            node = node -> child[1-bit];
        }
        else{
            node = node -> child[bit];
        }
    }
    return maxOr;
}
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> prefXor(n);
    prefXor[0] = v[0];
    for(int i = 1; i < n; i++){
        prefXor[i] = prefXor[i-1] ^ v[i];
    }
    TrieNode* root = new TrieNode();
    int maxOr = *max_element(v.begin(),v.end());
    for(int i = 0; i < n; i++){
        insert(root, prefXor[i]);
        maxOr = max(maxOr, query(root,prefXor[i]));
    }
    cout << max(maxOr,prefXor.back()) << endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
