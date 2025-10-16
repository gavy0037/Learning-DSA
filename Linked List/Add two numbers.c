/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include<stdio.h>
#include<stdlib.h>


  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head ;//dummy head
    head.next = NULL ;
    struct ListNode *tail = &head ;
    int c = 0 ;
    while(l1 != NULL || l2 != NULL || c){
        int val1 = l1 != NULL ? l1->val : 0 ;
        int val2 = l2 != NULL ? l2->val : 0 ;

        int sum= (val1+val2+c);
        int s = sum%10 ;
        c = sum/10 ;

        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(*newnode));
        newnode->val= s ;
        newnode->next = NULL ;
        tail->next = newnode ;
        tail = newnode ;

        if(l1 != NULL) l1 = l1 -> next ;
        if(l2 != NULL) l2 = l2 -> next ;
    }
    return head.next ;
}