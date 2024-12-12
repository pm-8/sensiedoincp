#include<iostream>
#include<vector>
using namespace std;
struct segmenttree{
    int n;
    vector<int> st,lazy;
    void init(int _n){
        this->n = _n;
        st.resize(4*n,0);
        lazy.resize(4*n,0);
    }
    int query(int start, int ending, int l, int r, int node){
        //non overlapping case
        if (start >  r  || ending < l) return 0;
        //lazy propagation / clear the propagation
        if(lazy[node]!=0){
            //updates the segment tree nodes
            st[node] += lazy[node]*(ending-start + 1);
            if(start != ending){
                //propagate the updated value
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
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
    void update(int start, int ending, int node, int l , int r, int value){
       //non overlapping case
        if (start >  r  || ending < l) return;
        //lazy propagation / clear the propagation
        if(lazy[node]!=0){
            //updates the segment tree nodes
            st[node] += lazy[node]*(ending-start + 1);
            if(start != ending){
                //propagate the updated value
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        //complete overlap
        if (start >= l && ending <= r){
            st[node] += value*(ending - start + 1);
            if(start != ending){
                lazy[2*node+1] += value;
                lazy[2*node+2] += value;
            }
            return;
        }
        // partial overlap case
        int mid = (start + ending)/2;
        update(start, mid, 2*node + 1, l , r , value);
        update(mid + 1, ending, 2*node + 2, l, r, value);
        st[node] = st[node*2 + 1] + st[node*2 + 2];
        return;
    }
    void update(int l , int r, int x){
        update(0, n-1, 0, l, r, x);
    }
};
using namespace std;
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    cout << tree.query(0,4) << endl;
    tree.update(0,1,10);
    cout << tree.query(0,4) << endl;
    // cout << tree.st[0] << endl;
    // cout << tree.query(2,5) << endl;
    // tree.update(2,9);
    // cout << tree.query(2,5) << endl;
    return 0;
}