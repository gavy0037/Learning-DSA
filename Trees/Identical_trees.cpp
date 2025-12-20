#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class TreeNode{
    public:
        int val ;
        TreeNode *right , *left ;
};


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL) return p == q ;

    if(p->val != q->val) return false ;

    TreeNode *left1 = p->left , *left2 = q->left;
    TreeNode *right1 = p->right ,  *right2 = q->right;

    return isSameTree(left1 , left2) & isSameTree(right1 , right2);
}
