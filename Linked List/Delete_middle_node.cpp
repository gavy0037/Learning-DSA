
/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.

*/

#include<iostream>

using namespace std ;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow , *fast , *prev;
        slow = fast = head ;
        if(head == NULL || head->next == NULL){
            return NULL ;
        }
        while(fast != NULL && fast->next != NULL){
            prev = slow ;
            slow = slow->next ;
            fast = fast->next->next ;
        }
        prev->next = slow->next ;

        return head ;
    }