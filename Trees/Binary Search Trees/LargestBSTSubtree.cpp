// C++ Program to find Size of Largest BST in a Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Information about the subtree: Minimum value,
// Maximum value, and Size of the largest BST
class BSTInfo {
  public:
    int min;
    int max;
    int mxSz;

    BSTInfo(int mn, int mx, int sz) {
        min = mn;
        max = mx;
        mxSz = sz;
    }
};

// Function to determine the largest BST in the binary tree
BSTInfo largestBSTBT(Node *root) {
    if (!root)
        return BSTInfo(INT_MAX, INT_MIN, 0);

    BSTInfo left = largestBSTBT(root->left);
    BSTInfo right = largestBSTBT(root->right);

    // Check if the current subtree is a BST
    if (left.max < root->data && right.min > root->data) {
        return BSTInfo(min(left.min, root->data), 
                       max(right.max, root->data), 1 + left.mxSz + right.mxSz);
    }

    return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
}

// Function to return the size of the largest BST
int largestBST(Node *root) {
    return largestBSTBT(root).mxSz;
}

int main() {
  
  	// Constructed binary tree looks like this:
    //         60
    //       /    \
    //      65     70
    //     /
    //   50

    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);

    cout << largestBST(root) << endl;

    return 0;
}