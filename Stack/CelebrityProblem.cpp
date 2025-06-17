#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>& mat){
    //if A knows B, A ain't a celebrity
    //if B doesn't knows A, A ain't a celebrity
    //B maybe a celebrity
    int n = mat.size();
    stack<int> st;
    for(int i = 0; i < n; i++){
        st.push(i);
    }
    while(st.size() > 1){
        int a = st.top();
        stack<int> st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(mat[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int c = st.top();
        st.pop();
        for(int i = 0; i < n; i++){
            if(i == c) continue;
            if(mat[c][i] || !mat[i][c]) return -1;
        }
        return c;
    }
}



int main()
{
vector<vector<int> > mat = {{ 0, 1, 0 },
                                { 0, 0, 0 },
                                { 0, 1, 0 }};
    cout << celebrity(mat);
    return 0;
}