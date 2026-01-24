#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std ;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void help(Node *root , map<int, int> &mp , int h_dis){ // THIS WILL NOT WORK AS IT IS NOT GARUNTEED THAT I WILL FIRST FIND THE TOP MOST NODE FOR THAT I NEED LEVEL ORDERED TRANSVERSAL
        if(root == NULL) return ;

        if(mp.find(h_dis) == mp.end()){
            mp[h_dis] = root->data ;
        }
        help(root->left , mp, h_dis-1);
        help(root->right , mp, h_dis+1);
    }
    vector<int> topView(Node *root) {
        // code here
        map<int, int>mp ;// horizontal distane -> value   
        queue<pair<int , Node*>>q ;


        q.push({0 , root});
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                Node *node = curr.second ;
                int dis = curr.first ;
                
                if(mp.find(dis) == mp.end()) mp[dis] = node->data ;
                
                if(node->left) q.push({dis-1 , node->left});
                if(node->right) q.push({dis+1 , node->right});
            }
        }
        
        vector<int>ans ;
        for(auto &i : mp){
            ans.push_back(i.second);
        }
        return ans ;
    }
};