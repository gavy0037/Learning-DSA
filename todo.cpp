/*
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 
*/

#include<iostream>

using namespace std ; 

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    bool help(Node *p , Node *q , int target){
        if(!p || !q) return false ;
        int sum = p->data + q->data ;
        if( sum == target) return true ;
        
        else if(sum < target){
            return help(p->right , q , target);
        }
        return help(p , q->left , target);      
    }
    bool findTarget(Node *root, int target) {
        // your code here.

    }
};

int main(){

    return 0;
}