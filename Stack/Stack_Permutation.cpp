#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool checkPerm(vector<int>& a, vector<int>& b)
{
    stack<int> st;
    int j = 0;
    for(int i = 0; i < a.size(); i++){
        st.push(a[i]);
        while(!st.empty() && st.top() == b[j]){
            st.pop();
            j++;
        }
    }
    return (j == b.size());
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};

    checkPerm(a, b);  

    return 0;
}