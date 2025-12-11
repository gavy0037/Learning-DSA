#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val ;
    struct node*next ;
}node ;

void print(node* head){
    while(head){
        printf("%d ",head->val);
        head = head->next ;
    }
    printf("\n");
}

node* mid(node *head){
    if(head == NULL) return NULL ;
    else if(head->next == NULL) return head ;
    node *slow = head , *fast = head->next ;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow ;
}

node* merge(node *left , node *right){
    node *dummy_head = malloc(sizeof(node));
    node *temp = dummy_head ;
    while(left != NULL && right != NULL){
        if(left->val <= right->val){
            temp->next = left ;
            left = left->next ;
            temp = temp->next ;
        }else{
            temp->next = right ;
            right = right->next ;
            temp = temp->next ;
        }
    }
    if(left) temp->next = left ;
    if(right) temp->next = right ;

    return dummy_head->next ;
}

node* sort(node *head){
    if(head == NULL || head->next == NULL) return head ;
    node *middle = mid(head);
    if(middle != NULL){
        node *temp = middle->next ;
        middle->next = NULL ;
        head = sort(head);
        temp = sort(temp);

        head = merge(head , temp);
        return head ;
    }
    return NULL ;
}

int main(){
    int n;
    scanf("%d",&n);
    node *head = NULL , *temp ;
    for(int i = 0 ; i < n; i++){
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&(newnode->val));
        newnode->next = NULL ;
        if(head == NULL) head = temp = newnode ;
        else{
            temp->next = newnode ;
            temp = newnode ;
        }
    }
    print(head);
    head = sort(head);

    print(head);

    return 0 ;
}