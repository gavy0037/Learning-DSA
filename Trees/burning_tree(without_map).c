#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val ;
    struct Node *left , *right ;
}Node ;


int time = -1 ;
int burn(Node *root , int target , int *dis){// this function returns the height and dis is used to track dis of node from target
    if(root == NULL) return 0 ;

    if(root->val == target){
        *dis = 0 ;
        int lh = burn(root->left , target , dis);
        int rh = burn(root->right , target , dis);

        time = max(time , max(lh , rh));

        return 1+max(lh,rh);
    }

    int left_dis = -1 , right_dis = -1 ;
    int lh = burn(root->left , target , &left_dis);
    int rh = burn(root->right , target , &right_dis);

    if(left_dis != -1){
        *dis = 1+left_dis ;

        time = max(time, 1+left_dis+rh);
    }else if(right_dis != -1){
        *dis = 1+right_dis ;

        time = max(time ,1+right_dis+lh);
    }

    return 1+max(lh , rh);
}

