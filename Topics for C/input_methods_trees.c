#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int val;
    struct Node *left , *right ;
}Node ;


Node *init(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val ;
    newnode->left = newnode->right = NULL ;

    return newnode ;
}

Node *insert_in_bst(Node *root , int val){
    if(root == NULL) return init(val);

    if(val < root->val){
        root->left = insert_in_bst(root->left , val);
    }else if(val > root->val) insert_in_bst(root->right,  val);

    return root ;
}

// build tree from inorder and preorder

Node *build_pre_in(int inorder[] , int preorder[], int *pre_idx , int in_st , int in_end , int n){
    if(in_end < in_st || *pre_idx >= n) return NULL ;

    Node *root = init(preorder[*pre_idx]);
    (*pre_idx)++;
    int i ;
    for(i = in_st ; i <= in_end ; i++){
        if(inorder[i] == preorder[*pre_idx]) break ;
    }

    root->left = build_pre_in(inorder , preorder , pre_idx , in_st , i-1 , n);
    root->right = build_pre_in(inorder, preorder , pre_idx , i+1 ; in_end , n);

    return root ;
}

// for post order i will just initialize the pre_idx like iterator to n-1

//build tree with left at 2*i+1 and right at 2*i+2

Node *build_with_indices(int n , int arr[]){
    Node *arr[n];

}


// level order transversal

void print_lvl_ordered(Node *root , int n ){
    // n is the total numbr of nodes
    Node *queue[n];
    int st = -1 , end = -1 ;
    st = 0 ;
    queue[++end] = root ;
    while(st != -1){
        Node *curr = queue[st];
        st++;
        if(st > end) st = end = -1 ;

        int size ;
        if(st == -1) size = 0 ;
        printf("%d ",curr->val);
        if(curr->left){
            if(st == -1) st =0 ;
            queue[++end] = curr->left ;
        }
        if(curr->right){
            if(st == -1) st =0;
            queue[++end] = curr->right ;
        }
    }
}

void print_lvl_ordered_leveled(Node *root , int n ){
    // n is the total numbr of nodes
    Node *queue[n];
    int st = 0 , end = -1 ;
    queue[++end] = root ;
    while(st <= end){
        int size = end-st+1 ;
        while(size--){
            Node *curr = queue[st];
            st++;
            printf("%d ",curr->val);

            if(curr->left){
                queue[++end] = curr->left ;
            }
            if(curr->right){
                queue[++end] = curr->right ;
            }            
        }
        printf("\n");
    }
}


typedef struct q{
    Node *node ;
    int hd , depth; 
}queue ;

void print_top_view(Node *root , int n){
    queue q[n];

    if(root == NULL) return ;

    int st = 0 , end = -1 ;
    q[++end].node = root ;
    q[0].hd = 0 ;
    q[0].depth = 0 ;
    int hd[2*n+1][2];// it stores the value,depth
    // set hd to INT_MIN , random as i will check hd[i][0] first

    int min_hd = INT_MAX , max_hd = INT_MIN ;
    while(st <= end){
        Node *curr = q[st].node;
        int dis = q[st].hd ;
        int dep = q[st].depth ;
        st++;

        if(dis < min_hd) min_hd = dis ;
        if(dis > max_hd) max_hd = dis ;
        if(hd[dis+n] == INT_MIN){
            hd[dis+n][0] = curr->val ;
            hd[dis+n][1] = dep ;
        }else{
            if(dep == hd[dis+n][1]) hd[dis+n][1] = min(hd[dis+n][0] , curr->val);
        }

        if(curr->left){
            end++ ;
            q[end].node = curr->left ;
            q[end].hd = dis-1;
            q[end].depth = dep+1 ;
        }
        if(curr->right){
            end++ ;
            q[end].node = curr->right ;
            q[end].hd = dis+1;
            q[end].depth = dep+1 ;
        }
    }

    for(int i = min_hd ; i <= max_hd ; i++){
        printf("%d ",hd[n+i][0]);
    }
}