/*

PROBLEM STATEMENT

Given the head of a singly linked list, reverse the list, and return the reversed list.

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val ;
    struct node* next ;
} Node ;

void printll(Node* head){
    //head is copied by value so we can change it
    while(head != NULL){
        printf("%d->",head->val);

        head = head->next ;
    }
    printf("NULL\n");
    return ;
}

int main(){
    int n ;
    scanf("%d",&n);
    Node *head = (Node*)malloc(sizeof(*head));//head of our input linked list
    Node *tail = (Node*)malloc(sizeof(*tail));

    head = tail = NULL ;
    
    for(int i = 0 ; i < n ; i++){//Take the linked list as input
        Node *newnode = (Node*)malloc(sizeof(*newnode));
        int a ;
        scanf("%d",&a);
        newnode->val = a ;
        newnode->next = NULL ;
        if(head == NULL){
            head = tail = newnode ;
        }else{
            tail->next = newnode ;
            tail = newnode ;
        }
    }

    printf("BEFORE REVERSAL: ");
    printll(head);

    Node *prev = NULL , *curr = head , *next = NULL ;
    while(curr != NULL){//reverse the linked list
        next = curr->next ;
        curr->next = prev ;

        prev = curr ;
        curr = next ;
    }

    head = prev ;

    printf("AFTER REVERSAL: ");
    printll(head);

    return 0 ;
}