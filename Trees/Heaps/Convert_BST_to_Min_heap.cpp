/*
You are given a 'ROOT' of a binary search tree of integers. The given BST is also a complete binary tree.

Your task is to convert the given binary search tree into a Min Heap
*/

#include<iostream>
#include<vector>

using namespace std ;


class Node{
    public:
        int val ;
        Node *right, *left ;

        Node(int val){
            this->val = val ;
            this->right = this->left = NULL ;
        }
};

void inorder(Node *root , vector<int> &nums){
    if(root== NULL) return ;
    inorder(root->left , nums);
    nums.push_back(root->val);
    inorder(root->right , nums);
}

void use_preOrder(Node *root , int &idx , vector<int> &nums){
    if(root == NULL || idx >= nums.size()) return ;

    root->val = nums[idx++];

    use_preOrder(root->left , idx , nums);
    use_preOrder(root->right , idx , nums);
}

void Convert_to_MinHeap(Node *root){
    if(root == NULL) return ;
    vector<int>nums ;
    inorder(root  , nums);
    int idx = 0 ;
    use_preOrder(root , idx , nums);
}