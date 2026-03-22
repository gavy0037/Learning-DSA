#include<iostream>
#include<vector>

using namespace std ;

class Node{
    public:
    int val ;
    Node *left , *right ;
    Node (int val){
        this->val = val ;
        this->left = this->right = NULL ;
    }
};

Node *insert(Node *root , int val){
    if(root == NULL) return new Node(val);

    if(val < root->val) root->left = insert(root->left , val);
    else root->right = insert(root->right , val);

    return root ;
}

int UB(Node *root , int val){
    if(root == NULL) return -1 ;
    if(root->val > val){
        int x = UB(root->left , val);
        if(x == -1) return root->val ;
        return min(root->val , x);
    }

    return UB(root->right , val);
}


vector<int> findLeastGreater(vector<int>& arr, int n) {
    vector<int> ans(n);
    ans[n-1] = -1 ;
    Node *root = new Node(arr[n-1]);
    for(int i = n-2 ; i >= 0 ; i--){
        ans[i] = UB(root , arr[i]);
        root = insert(root , arr[i]);
    }

    return ans ;
}