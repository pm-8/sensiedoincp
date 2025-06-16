// C++ implementation to check if the given array 
// can represent Level Order Traversal of Binary 
// Search Tree
#include <bits/stdc++.h>
using namespace std;

// Class to store node value, and
// its lower and upper subtree range.
class Data {
public:
    int node, start, end;
    Data (int x, int y, int z) {
        node = x;
        start = y;
        end = z;
    }
};



bool levelOrderOfBST(vector<int> arr){
    int n = arr.size();

    if(n==0) return true;

    queue<Data*> q;

    q.push(new Data(arr[0],INT_MIN,INT_MAX));

    int index = 1;

    while(index != n && !q.empty()){
        Data* front = q.front();
        q.pop();
        int node = front -> node;
        int start = front-> start;
        int end = front -> end;

        if(start <= arr[index] && arr[index] < node){

            q.push(new Data(arr[index],start,node-1));

            index++;
        }
        if(index < n && node < arr[index] && arr[index] <= end){
            q.push(new Data(arr[index],node+1,end));
            index++;
        }
    }
    if(index == n) return true;
    return false;
}

int main() {
    vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};    
 
    if (levelOrderIsOfBST(arr))
        cout << "True";
    else
        cout << "False";  
        
    return 0;    
}