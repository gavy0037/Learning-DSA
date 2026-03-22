#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std ;

class Node{
    public:
    int val ;
    Node *left, *right ;
};

class info{
    public:
        int sum , minimum, maximum , BST; 
        info(int sum , int minimum, int maximum , bool flag){
            this->minimum = minimum ;
            this->maximum = maximum ;
            this->sum = sum ;
            this->BST = flag ;
        }
};

class Solution {
public:
    int max_sum = 0 ;
    info* helper(Node *root){
        if(root == NULL) return new info(0 , INT_MAX , INT_MIN, true);

        info *left = helper(root->left);
        info *right = helper(root->right);
        int newsum = root->val + left->sum + right->sum ;
        if(left->BST && right->BST && left->maximum < root->val && right->minimum> root->val){
            max_sum = max(max_sum , newsum);
            return new info(newsum , min(left->minimum, root->val) , max(root->val , right->maximum) , true);
        }

        return new info(0 , 0, 0 , false);
    }
    int maxSumBST(Node* root) {
        helper(root);

        return max_sum ;
    }
};