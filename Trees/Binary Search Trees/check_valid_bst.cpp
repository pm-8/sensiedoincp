// C++ program to check if a tree is BST
// Using specified range of Min and Max Values

#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


bool isUtil(Node* root, int mini, int maxi){
    if(root == nullptr) return true;
    if(root->data < mini || root->data > maxi){
        return false;
    }
    return isUtil(root->left,mini,root->data - 1)&&isUtil(root->right,root->data+1,maxi);
}

bool isBST(Node* root){
    return isUtil(root,INT_MIN,INT_MAX);
}

int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}
