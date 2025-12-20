/*
    To print all the nodes of a binary tree on kth level
    The levels are numbered 1 to n
    1<= k <=n

*/

#include<iostream>
#include<queue>

using namespace std ;

class node{
    public:
        int val ;
        node *left , *right ;

        node(int val){
            this->val = val ;
            left = right = NULL ;
        }
};

void print_kth_level(node *root , int k){
    queue<node*>q ;
    q.push(root);
    q.push(NULL);

    int level = 1 ;
    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                level++;
                if(level > k) break ;
                q.push(NULL);
                continue ;
            }else{
                break ;
            }
        }else{
            if(level == k) cout<<curr->val<<" ";
        }
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

void print_kth_lvl_using_recursion(node *root , int k , int curr_lvl){ // we can simply our function by decrementing k and setting base case as k == 1
    if(root == NULL || curr_lvl > k) return ;

    if(curr_lvl == k){
        cout<<root->val<<" ";
        return ;
    }

    print_kth_lvl_using_recursion(root->left , k , curr_lvl+1);
    print_kth_lvl_using_recursion(root->right , k , curr_lvl+1);
}