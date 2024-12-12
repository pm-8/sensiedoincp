//great question for further understanding of depths
#include <bits/stdc++.h>
#define int long long int
using namespace std;
struct SegmentTree{
    int n;
    vector<int> st;
    void init(int _n){
        this->n = _n;
        st.resize(4*n,0);
    }
    void build(int v, int nl, int nr, int depth, vector<int> &a){
        if(nl == nr){
            st[v] = a[nl];
        }
        else{
            int mid = (nl+nr)/2;
            build(2*v,nl,mid,depth-1,a);
            build(2*v+1,mid+1,nr,depth-1,a);
            if(depth%2 == 0){
                st[v] = st[2*v] ^ st[2*v+1];
            }
            else{
                st[v] = st[2*v] | st[2*v+1];
            }
        }
    }
    void update(int v, int nl, int nr, int pos, int val, int depth){
        if(nl == nr){
            st[v] = val;
        }
        else{
            int mid = (nl+nr)/2;
            if(pos <= mid){
                update(2*v, nl, mid, pos, val, depth - 1);
            }
            else{
                update(2*v+1, mid + 1, nr, pos, val, depth - 1);
            }
            if(depth % 2 == 0){
            st[v] = st[2*v] ^ st[2*v+1];
            }
            else{
                st[v] = st[2*v] | st[2*v+1];
            }
        }
        
    }
    
};
void solve() {
    SegmentTree tree;
    int n;
    cin >> n;
    int q;
    cin >> q;
    int N = 1 << n;
    tree.init(N);
    vector<int> v(N);
    for(int &x : v){
        cin >> x;
    }
    tree.build(1, 0, N - 1, n, v);
    while(q--){
        int x,y;
        cin >> x >> y;
        tree.update(1, 0, N - 1, x - 1, y, n);
        cout << tree.st[1] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opp.txt", "w", stdout);
#endif
        solve();
    
}