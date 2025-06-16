// C++ program to find the maximum sum of 
// non-adjacent nodes in a binary tree.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;     
    Node *left, *right; 
    
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

int getMaxSumUtil(Node* node){
    if(node == nullptr){
        return 0;
    }
    int incl = node->data;
    if(node->left){
        incl += getMaxSumUtil(node->left->left) + getMaxSumUtil(node->left->right);
    }
    if(node->right){
        incl += getMaxSumUtil(node->right->left) + getMaxSumUtil(node->right->right);
    }
    int excl = 0;
    if(node->left){
        excl += getMaxSumUtil(node->left);
    }
    if(node->right){
        excl += getMaxSumUtil(node->right);
    }
    return max(incl,excl);
}

int getMaxSum(Node* root){
    if(root == nullptr){
        return 0;
    }

    return getMaxSumUtil(root);
}

int main() {
  
    // Creating a binary tree with the following structure:
    //          1
    //         / \
    //        2   3
    //       /   / \
    //      1   4   5

    Node* root = new Node(1);           
    root->left = new Node(2);             
    root->right = new Node(3);           
    root->right->left = new Node(4);     
    root->right->right = new Node(5);     
    root->left->left = new Node(1);       

    cout << getMaxSum(root) << endl;
    return 0;
}