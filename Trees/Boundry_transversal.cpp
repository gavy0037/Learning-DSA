#include<iostream>
#include<vector>

using namespace std ;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    private:
    bool isleaf(Node *root){
        return root->left == NULL && root->right == NULL ;
    }
    void getLeftNodes(Node *root , vector<int> &ans){
        if(root == NULL) return ;
        Node *temp = root->left ;
        while(temp){
            if(!isleaf(temp)) ans.push_back(temp->data);
            if(temp->left) temp = temp->left ;
            else temp = temp->right ;
        }
    }
    void getRightNodes(Node *root , vector<int> &ans){
        if(root == NULL) return ;
        Node *temp = root->right ;
        vector<int>t ;
        while(temp){
            if(!isleaf(temp)) t.push_back(temp->data);

            if(temp->right) temp = temp->right ;
            else temp =temp->left ;
        }

        for(int i = t.size()-1 ; i>=0 ; i--){
            ans.push_back(t[i]);
        }
    }

    void getLeafs(Node *root , vector<int> &ans){
        if(root == NULL) return ;

        if(isleaf(root)) ans.push_back(root->data);

        getLeafs(root->left , ans);
        getLeafs(root->right , ans);
    }
    public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans ;
        if(!isleaf(root)) ans.push_back(root->data);
        getLeftNodes(root , ans);
        getLeafs(root , ans);
        getRightNodes(root , ans);
        return ans ;
    }
};