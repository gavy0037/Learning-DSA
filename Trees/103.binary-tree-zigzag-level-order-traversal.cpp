#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        queue<TreeNode*>q;
        if(!root) return ans ;
        bool leftToRight = true ;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size) ;
            for(int i = 0 ; i < size ; i++){
                TreeNode *curr = q.front();
                q.pop();

                int idx = leftToRight ? i : size-i-1 ;
                level[idx] = curr->val ;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
            leftToRight = !leftToRight ;
        }

        return ans ;
    }
};
// @lc code=end

