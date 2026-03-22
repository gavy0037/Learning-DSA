#include<stdio.h>
#include<stdlib.h>

#define TABLESIZE 500009

typedef struct Node{
    int key , val ;
    long long sum ;
    int count ;
    struct Node *next ;
}Node ;

void init(Node *hash_table[]){
    for(int i = 0 ; i < TABLESIZE ; i++){
        hash_table[i] = NULL ;
    }
}

long long hash(long long key){ return ((key%TABLESIZE) + TABLESIZE)%TABLESIZE  ;}



void insert_or_increment(Node *hash_table[] , long long key){
    long long idx = hash(key);
    Node *temp = hash_table[idx];

    while(temp != NULL){
        if(temp->key == key){
            temp->val++ ;
            return ;
        }
        temp = temp->next ;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key ;
    newnode->val = 1 ;
    newnode->next = NULL ;
    
    newnode->next = hash_table[idx];
    hash_table[idx] = newnode ;
}

void insert(Node *hash_table[] , long long key , long long val){
    int idx= hash(key);
    
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key ;
    newnode->val = val ;
    newnode->next = hash_table[idx];
    hash_table[idx] = newnode ;
}

int search_first(Node *hash_table[] , int key){
    int idx = hash(key);
    Node *temp = hash_table[idx];
    while(temp){
        if(temp->key == key) return temp->val ;
        temp = temp->next ;
    }
    return -1 ;
}
long long search(Node *hash_table[] , long long key){
    long long idx = hash(key);
    Node *temp = hash_table[idx];
    while(temp != NULL){
        if(temp->key == key) return temp->val ;
        temp = temp->next ;
    }
    return 0 ;
}

int search_last(Node *hash_table[] , int key){
    long long idx = hash(key);
    Node *temp = hash_table[idx];
    int ans = -1 ;
    while(temp != NULL){
        if(temp->key == key) ans = temp->val;
        temp = temp->next ;
    }
    return ans ;
}

Node *hash_table[TABLESIZE];

int main(){
    int t ;
    scanf("%d",&t);
    while(t--){
        init(hash_table);
        int n ;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            int arri ;
            scanf("%d",&arri);
            insert(hash_table , arri , i);
        }
        int q ;
        while(q--){
            int u , v ;
            scanf("%d %d",&u , &v);
            int f = search_last(hash_table , u) , s = search_first(hash_table , v);

            //printf("%d %d\n" , f , s);
            if(f == -1 || s == -1 || f > s){
                printf("No\n");
            }else printf("Yes\n");
        }
    }

    return 0 ;
}
