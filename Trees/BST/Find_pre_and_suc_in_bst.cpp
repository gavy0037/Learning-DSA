#include<iostream>
#include<vector>

using namespace std ; 

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *findpre(Node *root){//returns largest
    Node *temp = root ;
    while(temp->right != NULL) temp = temp->right ;
    return temp ;
}
Node *findsuc(Node *root){//returns smallest
    Node *temp = root ;
    while(temp->left != NULL) temp = temp->left ;
    return temp ;
}

vector<Node*> findPreSuc(Node* root, int key) {
    // code here
    Node *temp = root ;
    Node *pre = NULL, *suc = NULL;
    while(temp){
        if(temp->data < key){
            pre = temp ;
            temp = temp->right ;
        }else if(temp->data > key){
            suc = temp ;
            temp = temp->left ;
        }else{
            if(temp->left) pre = findpre(temp->left);
            if(temp->right) suc = findsuc(temp->right);
            break ;
        }
    }
    return {pre , suc};
}