#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} Node;

void printReverse(Node *head) {
    if (head == NULL) return ;
    printReverse(head->next) ;
    
    printf("%d ", head->val) ;
}

int main() {
    Node *head = NULL, *tail = NULL ;
    int a ;

    while (scanf("%d",&a) , a != -1) {
        Node *newnode = malloc(sizeof(*newnode)) ;
        newnode->val = a ;
        newnode->next = NULL ;
        if(head == NULL) head = tail = newnode;
        else{ 
            tail->next = newnode; tail = newnode; 
        }
    }

    printReverse(head);

    // Free memory
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}