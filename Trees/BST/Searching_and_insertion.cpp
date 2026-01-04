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

Node* insert(Node *root , int val){ // logn time
    // think for iterative function as well: for that i need to keep track of the parent node as well

    if(root == NULL) return new Node(val);

    if(val < root->val) root->left = insert(root->left , val);
    else root->right = insert(root->right , val);

    return root ;

}

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

bool search(Node *root , int val){
    if(root == NULL) return false ;

    if(root->val == val) return true ;
    else if(root->val < val) return search(root->right , val);

    return search(root->left , val);
}

int main(){
    return 0 ;
}