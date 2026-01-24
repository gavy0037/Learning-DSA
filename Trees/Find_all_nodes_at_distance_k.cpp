/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std ;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} ;

void make_parent_map(unordered_map<TreeNode* , TreeNode*> &mp, TreeNode *root){
    if(root == NULL) return ;

    if(root->left) mp[root->left] = root ;
    make_parent_map(mp , root->left);
    if(root->right) mp[root->right] = root ;
    make_parent_map(mp , root->right);
}

vector<int> helper(TreeNode *root , TreeNode *target , int k , unordered_map<TreeNode* , TreeNode*> &parent ){
    if( k == 0){
        return {target->val};
    }
    queue<pair<int , TreeNode*>>q ;// distance , node
    unordered_set<TreeNode*>st ;
    st.insert(target);
    vector<int>ans ;
    q.push({0 , target});
    while(!q.empty()){
        int size = q.size();

        for(int i = 0 ;i < size ; i++){
            int dis = q.front().first ;
            TreeNode *node = q.front().second ;
            st.insert(node);
            q.pop();
            if(dis == k){
                ans.push_back(node->val);
            }

            if(node->left && st.find(node->left) == st.end()) q.push({dis+1 , node->left});
            if(node->right && st.find(node->right) == st.end()) q.push({dis+1 , node->right});
            if(parent.find(node) != parent.end() && parent[node] != NULL && st.find(parent[node]) == st.end())
                q.push({dis+1 , parent[node]});
        }


    }

    return ans ;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode* , TreeNode*> to_parent ; // child -> parent
    make_parent_map(to_parent , root);
    return helper(root , target , k , to_parent);
}
 
int main(){

}