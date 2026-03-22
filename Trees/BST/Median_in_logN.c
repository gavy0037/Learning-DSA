#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val , right_size , left_size ;
    struct Node *left  , *right ;
} Node ;

Node *init(int val , int left_size , int right_size){
    Node *newn = (Node*)malloc(sizeof(Node));
    newn->val = val ;
    newn->right_size = right_size ;
    newn->left_size = left_size ;

    newn->left = newn->right = NULL ;

    return newn ;
}

Node *build(int *arr, int st , int end){
    if(st > end) return NULL ;
    int mid = (st+end)/2 ;
    Node *root = init(arr[mid] , mid-st , end-mid);
    root->left = build(arr , st , mid-1);
    root->right = build(arr , mid+1 , end);

    return root ;
}

Node *delete(Node *root , int val){
    if(root == NULL) return NULL ;

    if(val > root->val){
        root->right_size--;
        root->right = delete(root->right , val);
    }else if(val < root->val){
        root->left_size-- ;
        root->left = delete(root->left , val);
    }else{
        if(!root->left && !root->right) return NULL ;
        else if(!root->left || !root->right) return root->left == NULL ? root->right : root->left ;

        Node *temp = root->right ;

        while(temp && temp->left) temp = temp->left ;

        root->right_size-- ;
        root->val = temp->val ;

        root->right = delete(root->right , temp->val);
    }

    return root ;
}

int median(Node *root , int k){
    if(root == NULL) return -1 ;

    if(k <= root->left_size) return median(root->left , k);
    else if(k == root->left_size + 1) return root->val ;

    return median(root->right , k - root->left_size-1);
}

int cmp(const void *a , const void *b){
    int *x = (int*)a ;
    int *y = (int*)b ;

    return *x - *y ;
}

int main(){
    int t ;
    scanf("%d" , &t);
    while(t--){
        int n , q , k;
        scanf("%d %d",&n , &q);
        k = n ;
        int arr[n] , temp[n];
        for(int i = 0 ; i < n ; i++){
            scanf("%d" , &arr[i]);
            temp[i] = arr[i];
        }

        qsort(arr , n , sizeof(arr[0]) , cmp);
        Node *root = build(arr, 0 , n-1);

        while(q--){
            int i ;
            scanf("%d",&i);
            if(k == 0) printf("-1\n");
            else{
                if(!(temp[i-1] == -1)){
                    k-- ;
                    root = delete(root , temp[i-1]);
                    temp[i-1] = -1 ;
                }
                int ceil = k%2==0 ? k/2 : k/2+1 ;
                printf("%d\n" , median(root , ceil));
            }
        }
    }

    return 0 ;
}