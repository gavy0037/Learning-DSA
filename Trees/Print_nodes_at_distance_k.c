#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val ;
    struct Node *left , *right ;
} Node ;

Node *init(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val ;
    newnode->left = newnode->right = NULL ;

    return newnode ;
}

// If root == target then print all nodes in its subtree at distance 

void print_nodes_at_k(Node *root , int dis){
    if(root == NULL){
        return ;
    }

    if(dis == 0){
        print("%d ",root->val);
        return ;
    }
    print_nodes_at_k(root->left , dis-1);
    print_nodes_at_k(root->right, dis-1);
}

int handle_parents_at_dis_k(Node *root , int k , int target){
    if(root == NULL) return -1 ;

    if(root->val == target){
        print_nodes_at_k(root , k);
        return 0 ;
    }

    int left = handle_parents_at_dis_k(root->left , k , target);
    if(left != -1){
        // then target exist in left subtree
        // now left is the dis of root's left from target node

        // handle the case where root is at distance k
        if(left+1 == k){
            print("%d ",root->val);
        }else{
            // so i need to print all the nodes in the right subtree of root at distance k - left - 2
            // 2 for the 2 edges that i will travel from root->left to root->right node

            print_nodes_at_k(root->right , k - left -2);
        }
        return left+1 ;    

    }
    int right = handle_parents_at_dis_k(root->right , k , target);
    if(right != -1){
        if(right+1 == k){
            print("%d " , root->val);
        }else{
            print_nodes_at_k(root->left , k-right-2);
        }

        return right+1 ;
    }

    return -1 ;

}