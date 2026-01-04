// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

#include<iostream>

using namespace std ;

class TreeNode{
    public:
        int val ;
        TreeNode *left , *right ;
};

TreeNode *prev_node = NULL, *first = NULL , *second = NULL ;

void help(TreeNode *root){
    if(root == NULL) return ;

    help(root->left);

    //prev_node = root->left ;
    if(prev_node!=nullptr && prev_node->val > root->val){
        if(first == nullptr) first = prev_node ;
        second = root ;
    }
    prev_node = root ;

    help(root->right);
}
void recoverTree(TreeNode* root) {
    help(root);
    swap(first->val , second->val);
}