#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int count , d , a ;

    struct Node *left,  *right ;
} Node ;

Node* init(int a , int d , int count){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->count = count ;
    newnode->d = d ;
    newnode->a = a ;

    return newnode ;
}

int greater(int a1 , int d1, int a2 , int d2){
    if(a1 + d1 != a2+ d2) return a1 + d1 > a2 + d2 ;


    return a1 > a2 ;
}

Node *insert(Node *root , Node * to_insert){
    if(root == NULL){
        return to_insert ;
    }

    if(root->a == to_insert->a && root->d == to_insert->d){
        root->count++ ;
        free(to_insert);
        return root ;
    }

    if(greater(root->a , root->d , to_insert->a , to_insert->d)){
        root->left = insert(root->left , to_insert);
    }else root->right = insert(root->right , to_insert);

    return root ;
}

void print_reverse(Node *root){
    if(root == NULL) return ;

    print_reverse(root->right);
    printf("%d %d %d\n" , root->a , root->d , root->count);
    print_reverse(root->left);

}
void count_nodes(Node *root , int* count){
    if(root == NULL) return ;

    (*count)++;
    count_nodes(root->left , count);
    count_nodes(root->right , count);

}

int accept(Node *root , int a , int d){ // tell if a node exists and it's count is > 1
    if(root == NULL) return 0 ;

    if(root->a == a && root->d == d) return root->count > 1; 

    if(greater(root->a , root->d , a , d)){
        return accept(root->left, a , d);
    }
    // else
    return accept(root->right , a , d);
}
Node* find(Node *root , int a , int d){ // tell if a node exists and it's count is > 1
    if(root == NULL) return NULL ;

    if(root->a == a && root->d == d) return root ; 

    if(greater(root->a , root->d , a , d)){
        return find(root->left, a , d);
    }
    // else
    return find(root->right , a , d);
}

void delete(Node *root , int a , int d){
    if(root == NULL) return ;

    if(root->a == a && root->d == d) root->count-- ;
    if(greater(root->a , root->d , a , d)) delete(root->left , a , d);
    else delete(root->right, a , d);
}

int main(){
    int n ;
    scanf("%d",&n);

    int a , d ;
    scanf("%d %d",&a , &d) ;
    Node *root = init(a , d , 1);

    for(int i = 1 ; i < n ; i++){
        scanf("%d %d",&a , &d);
        Node *to_insert = init(a , d , 1);
        root = insert(root , to_insert);
    }
    int q ;
    scanf("%d",&q);
    while(q--){
        char s[6];
        scanf(" %s",s);

        int a1 , d1, a2 , d2 ;
        scanf("%d %d %d %d",&a1 , &d1 , &a2 , &d2);

        if(a2 != -1 && !accept(root , a2 ,d2)){
            printf("0\n");
        }else if(a2 == -1){
            printf("1\n");
            root = insert(root , init(a1 , d1 , 1));
        }else{
            if(!find(root , a1 , d1)){
                printf("1\n");
                delete(root , a2 , d2);
                root = insert(root , init(a1 , d1 , 1));
            }else{
                if(greater(a2, d2 , a1 ,d1)) printf("0\n");
                else{
                    printf("1\n");
                    delete(root , a2 , d2);
                    root = insert(root , init(a1 , d1 , 1));
                }
            }
        }
    }

    // print_count
    int count = 0 ;
    count_nodes(root , &count);
    printf("%d\n" ,count);

    print_reverse(root);
}