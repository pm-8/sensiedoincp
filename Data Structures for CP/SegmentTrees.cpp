#include<iostream>
#include<vector>
using namespace std;
struct segmenttree{
    int n;
    vector<int> st;
    void init(int _n){
        this->n = _n;
        st.resize(4*n,0);
    }
    int query(int start, int ending, int l, int r, int node){
        //non overlapping case
        if (start >  r  || ending < l) return 0;
        //complete overlap
        if (start >= l && ending <= r) return st[node];
        // partial overlap case
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2*node+1);
        int q2 = query(mid + 1, ending, l, r, 2*node + 2);
        return q1+q2;
    }
    void build(int start, int ending, int node, vector<int> &v){
        //leaf nodes
        if (start == ending){
            st[node] = v[start];
            return;
        }
        int mid = (start + ending) / 2;
        //left subtree is (start,mid)
        build(start, mid, 2*node+1, v);
        //right subtree is (mid + 1, ending)
        build(mid+1, ending, 2*node + 2, v);

        st[node] = st[node*2+1] + st[node*2+2];
    }
    void build(vector<int> &v){
        build(0,v.size()-1,0,v);
    }
    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }
    void update(int start, int ending, int node, int index, int value){
        if(start == ending){
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if(index <= mid){
            update(start, mid, 2*node + 1, index, value);
        }
        else{
            update(mid + 1, ending, 2*node + 2, index, value);
        }
        st[node] = st[node*2+1] + st[node*2+2];
        return;
    }
    void update(int x, int y){
        update(0, n-1, 0, x, y);
    }
};
using namespace std;
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    cout << tree.st[0] << endl;
    cout << tree.query(2,5) << endl;
    tree.update(2,9);
    cout << tree.query(2,5) << endl;
    return 0;
}