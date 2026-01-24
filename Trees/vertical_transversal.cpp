#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<pair<int , int>>>mp ; // col-> row , value
        queue<pair<TreeNode* , pair<int, int>>>q ; // node , row, col

        q.push({root ,{0 , 0}});
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto c = q.front();
                q.pop();
                int col = c.second.second , row = c.second.first ;
                auto node = c.first ;

                mp[col].push_back({row , node->val});

                if(node->left) q.push({node->left , {row , col-1}});
                if(node->right) q.push({node->right , {row , col+1}});
            }
        }
        vector<vector<int>>ans ;
        for(auto &i : mp){
            auto v = i.second ;
            sort(v.begin() , v.end()); // if two nodes are at the same row then they will be sorted in order of value if not then sorted by row
            vector<int>temp ;
            for(auto j : v) temp.push_back(j.second);
            ans.push_back(temp);
        }

        return ans ;
    }
};