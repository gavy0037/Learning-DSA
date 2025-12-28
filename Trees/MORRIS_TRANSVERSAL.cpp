#include<iostream>
#include<vector>

using namespace std ;

class TreeNode{
    public:
        int val ;
        TreeNode *right , *left ;
};

vector<int> inorderTraversal(TreeNode* root) {
    TreeNode *curr = root ;
    vector<int>inorder ;
    while(curr){
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right ;
        }else{
            TreeNode *prev = curr->left ;
            while(prev->right && prev->right != curr) prev = prev->right ;
            
            if(prev->right == NULL){// a new thread is to form
                prev->right = curr ;
                curr = curr->left ;
            }else{// there already exists a thread as the loop exited due to the second condition
                prev->right = NULL ;
                inorder.push_back(curr->val);
                curr = curr->right ;
            }
        }
    }
    return inorder;
}