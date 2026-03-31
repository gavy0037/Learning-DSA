#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int count , d , a ;

    struct Node *left,  *right ;
} Node ;

Node* init(int a , int d , int count){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->count = count ;
    newnode->d = d ;
    newnode->a = a ;

    newnode->left = newnode->right = NULL ;
    return newnode ;
}

int greater(int a1 , int d1, int a2 , int d2){
    if(a1 + d1 != a2+ d2) return a1 + d1 > a2 + d2 ;


    return a1 > a2 ;
}

Node *insert(Node *root , int a, int d){
    if(root == NULL){
        return init(a , d,  1) ;
    }

    if(root->a == a && root->d == d){
        root->count++ ;
        return root ;
    }

    if(greater(root->a , root->d , a , d)){
        root->left = insert(root->left , a , d);
    }else root->right = insert(root->right , a , d);

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


void predecesor(Node *root , Node *temp , Node **pre){
    if(root == NULL) return ;

    if(temp->a == root->a && temp->d == root->d){
        //printf("(ROOT = TEMP)LEFT -> ROOT:(%d,%d)\n" , root->a, root->d);
        predecesor(root->left , temp , pre);
    }
    else if(greater(temp->a , temp->d, root->a , root->d)){
        (*pre) = root;
        //printf("(FOUND PRED) RIGHT : ROOT:(%d,%d)\n" , root->a, root->d);
        predecesor(root->right , temp , pre);
    }else{
        predecesor(root->left, temp, pre);
        //printf("LEFT : ROOT:(%d,%d)\n" , root->a, root->d);
    }
}
void successor(Node *root , Node *temp , Node **succ){
    if(root == NULL) return ;
    if(temp->a == root->a && temp->d == root->d) successor(root->right , temp , succ);
    else if(greater(root->a , root->d , temp->a , temp->d)){
        (*succ) = root;
        successor(root->left , temp , succ);
    }else successor(root->right, temp, succ);
}

int main(){
    int n ;
    scanf("%d",&n);

    int a , d ;
    scanf("%d %d",&a , &d) ;
    Node *root = init(a , d , 1);

    for(int i = 1 ; i < n ; i++){
        scanf("%d %d",&a , &d);
        root = insert(root , a , d);
    }
    int q ;
    scanf("%d",&q);
    while(q--){
        char s[8];
        scanf(" %s",s);

        if(strcmp(s , "TRADE") == 0){
            //printf("HIT TRADE\n");
            int a1 , d1, a2 , d2 ;
            scanf("%d %d %d %d",&a1 , &d1 , &a2 , &d2);

            if(a2 != -1 && !accept(root , a2 ,d2)){
                printf("0\n");
            }else if(a2 == -1){
                printf("1\n");
                root = insert(root , a1, d1);
            }else{
                if(!find(root , a1 , d1)){ // if find returns NULL
                    printf("1\n");
                    delete(root , a2 , d2);
                    root = insert(root , a1 , d1);
                }else{
                    if(greater(a2, d2 , a1 ,d1)) printf("0\n");
                    else{
                        printf("1\n");
                        delete(root , a2 , d2);
                        root = insert(root , a1 , d1 );
                    }
                }
            }
        }else{
            //printf("HIT COMAPARE : %s\n" , s);
            scanf("%d %d", &a , &d);
            Node *temp = find(root, a,  d);
            if(temp == NULL){
                printf("%d\n"  , 0 );
                
            }else{
                printf("%d\n" , temp->count);
            }
            Node *pre = NULL, *succ = NULL ;
            if(!temp) temp = init(a , d , 1);
            predecesor(root , temp , &pre);
            successor(root , temp , &succ);

            if(pre) printf("%d %d %d\n",  pre->a , pre->d, pre->count);
            else printf("-1\n");
            if(succ) printf("%d %d %d\n",  succ->a , succ->d, succ->count);
            else printf("-1\n");
            
        }
        
    }

    // print_count
    int count = 0 ;
    count_nodes(root , &count);
    printf("%d\n" ,count);

    print_reverse(root);

    return 0 ;
}