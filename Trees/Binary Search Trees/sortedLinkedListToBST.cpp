/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    TNode *constructBST(vector<int>& arr, int l, int r){
        if(l >= r) return nullptr;
        int mid = (r+l)/2;
        TNode* root = new TNode(arr[mid]);
        root -> left = constructBST(arr,l,mid);
        root->right = constructBST(arr,mid+1,r);
        return root;
    }
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int> arr;
        while(head){
            arr.push_back(head->data);
            head = head->next;
        }
        int n = arr.size();
        TNode* root = new TNode(0);
        return root = constructBST(arr,0,n);
    }
};