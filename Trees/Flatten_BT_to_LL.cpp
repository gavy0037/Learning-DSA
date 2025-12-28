#include<iostream>
#include<vector>

using namespace std ;

class Node{
    public:
        int val ;
        Node *right , *left ;
};

Node *temp = NULL;
void flatten(Node* root) {
    if(root == NULL) return ;

    flatten(root->right);
    flatten(root->left);
    
    root->left = NULL ;
    root->right = temp;

    temp = root ;
}