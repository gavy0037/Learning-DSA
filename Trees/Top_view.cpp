#include<iostream>
#include<queue>
#include<map>

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

vector<int> topView(Node *root) {
        // code here
    map<int , int>mp ; // contains distance and value pairs
    queue<pair<Node*,int>>q ; // contains node and distance pairs
    q.push({root , 0});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(mp.find(curr.second) == mp.end()){// distance does not exist
            mp[curr.second] = (curr.first)->data ;// distance and value stored in map
        }

        // For bottom view we just need to repalce above if statement with mp[curr.second] = (curr.first)->data  only

        if((curr.first)->left != NULL){
            q.push({(curr.first)->left , curr.second - 1});
        }
        if((curr.first)->right != NULL) q.push({(curr.first)->right ,curr.second+1});
    }
    vector<int>ans ;
    for(auto &i : mp){ // map is sorted in order of keys so distance is already sorted
        ans.push_back(i.second);
    }
    return ans;
}