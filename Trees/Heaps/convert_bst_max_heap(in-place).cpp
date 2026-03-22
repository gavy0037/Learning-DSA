/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.
*/

#include<iostream>
#include<vector>

using namespace std ;

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node ;

// For converting to a max-heap , we first store the inorder transversal of the tree , then we do preorder to make the tree into a max-heap , the same is done for min-heap but instead of preorder we do postorder transversal of the tree.

void in(Node *root , vector<int> &inorder){
    if(root == NULL) return ;
    in(root->left , inorder);
    inorder.push_back(root->data);
    in(root->right , inorder);
}
void f(Node *root , vector<int> &in , int &idx){
    if(root == NULL) return ;
    
    f(root->left , in , idx);
    f(root->right , in , idx);
    
    root->data = in[idx++];
}
void convertToMaxHeapUtil(Node* root) {
    // Your code goes here
    vector<int>inorder;
    in(root ,inorder);
    int idx = 0 ;
    f(root , inorder , idx);
}