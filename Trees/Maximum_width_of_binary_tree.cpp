#include<iostream>
#include<queue>

using namespace std;

class TreeNode{
    public:
        int val ;
        TreeNode *right , *left ;

        TreeNode(int val){
            this->val = val ;
            this->right = this->left = NULL ;
        }
};

int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0 ;

    int maxwidth = 0 ;
    queue<pair<TreeNode* , int>>q ;
    q.push({root , 0});
    while(!q.empty()){
        int size = q.size() , minidx = q.front().second;
        int first , last ;
        for(int i = 0 ;i < size ; i++){
            TreeNode *curr = q.front().first;
            int idx = q.front().second - minidx ;
            q.pop();
            
            if(i == 0) first = idx ;
            if(i == size-1) last = idx ;

            if(curr->left) q.push({curr->left , 2*idx+1});
            if(curr->right) q.push({curr->right , 2*idx+2});
        }
        maxwidth = max(maxwidth , last-first+1);
    }
    return maxwidth ;
}