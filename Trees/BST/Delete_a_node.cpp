#include<iostream>
#include<vector>

using namespace std ;

/*
    BST functions are written assuming that all the values in BST are unique
*/

class Node{
    public:
        int val ;
        Node *right , *left ;
        Node(int val){
            this->val = val ;
            this->right = this->left = NULL ;
        }
};

Node* insertIntoBST(Node* root, int val) {
    Node *newnode = new Node(val);
    newnode->right = newnode->left = NULL ;
    Node *temp = root ;
    
    while(temp){
        if(temp->val < val){
            if(temp->right == NULL){
                temp->right = newnode;
                return root ;
            }
            temp = temp->right ;
        }else{
            if(temp->left == NULL){
                temp->left = newnode ;
                return root ;
            }
            temp = temp->left ;
        }
    }
    return newnode ;
}