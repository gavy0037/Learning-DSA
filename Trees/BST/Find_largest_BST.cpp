#include<iostream>
#include<climits>

using namespace std ;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class info{
public:
    int size;
    int min , max ;

    info(int size , int min , int max){
        this->size = size ;
        this->min = min ;
        this->max = max ;
    }
};

class Solution {
  public:
    info helper(Node *root){
        if(root == NULL) return info(0 , INT_MAX , INT_MIN);
    
        auto left = helper(root->left);
        auto right = helper(root->right);
    
        if(left.max < root->data && right.min > root->data){
            return info(left.size + right.size +1 , min(left.min ,root->data) , max(right.max , root->data));
            // root value to handle cases of left or right being null;
        }
    
        return info(max(left.size , right.size) , INT_MIN , INT_MAX);
    }
    
    int largestBst(Node * root){
        return helper(root).size ;
    }
};