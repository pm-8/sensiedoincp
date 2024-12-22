#include<iostream>
#include<stack>
using namespace std;
stack<pair<int,int>> st;
int main()
{
    int q;
    cin >> q;
    while(q--){
        int new_elem;
        cin >> new_elem;
        int new_min = st.empty()?new_elem:min(new_elem,st.top().second);
        st.push({new_elem, new_min});
    }
    cout << st.top().second;
    return 0;
}