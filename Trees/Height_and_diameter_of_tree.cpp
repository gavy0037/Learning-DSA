#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std ;

class TreeNode{
    public:
        int val ;
        TreeNode *right, *left ;
};

int height_of_binaryTree(TreeNode *root){
    if(root == NULL) return -1 ;//as we have been asked for edges
    // if height defined as number of levels we return 0
    
    return 1 + max(height_of_binaryTree(root->left) , height_of_binaryTree(root->right));// as the length is by edges so we do not add 1
}

    // diameter of tree
    int ans = 0 ;
    int height(TreeNode *root){
        if(root == NULL) return 0 ;
        int lheight =height(root->left);
        int rheight = height(root->right); 

        ans = max(lheight+rheight , ans);
         
        return 1+max(lheight , rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans ;
    }

int main(){

}