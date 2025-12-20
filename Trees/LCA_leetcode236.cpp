#include<iostream>

using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root ;

        TreeNode *left = lowestCommonAncestor(root->left , p , q);
        TreeNode *right = lowestCommonAncestor(root->right , p , q);

        if(right && left) return root ; // both are not NULL

        return right == NULL ? left : right ;
    }
};
// auto init = atexit([](){ofstream("display_runtime.txt")<<"0";}); JUST TO GET 0MS ON LEETCODE
