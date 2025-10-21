/*
PROBLEM STATEMENT
    Given a linked list, swap every two adjacent nodes and return its head.
    You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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

ListNode* swapPairs(ListNode* head) {
        //for edge cases
        if(head == NULL || head->next == NULL) return head ;
        ListNode *prev , *curr = head, *next = head->next ; ;
        //make a dummy head pointer
        ListNode* dhead  = new ListNode() ;
        dhead->next = head ;
        prev = dhead ;

        while(curr != NULL && curr->next != NULL ){
            curr->next = next->next;
            prev->next = next ;
            next->next = curr ;

            prev = curr ;
            curr = curr->next ;
            if(curr == NULL) break ;
            next = curr->next ;
        }
        return dhead->next ;
    }