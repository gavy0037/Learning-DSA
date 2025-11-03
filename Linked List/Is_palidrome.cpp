/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
 
 bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head , *fast = head, *prev_slow = nullptr;

        while(fast != NULL && fast->next != NULL){
            prev_slow = slow;
            slow = slow->next ;
            fast = fast->next->next ;
        }
        if (prev_slow) prev_slow->next = nullptr; // Split the list into two halves
        ListNode *prev = NULL ;

        while(slow != NULL){
            ListNode* next = slow->next ;
            slow->next = prev ;

            prev = slow ;
            slow = next ;
        }

        ListNode *second = prev  , *first = head ;
        while(second != NULL){
            if(second->val != first->val) return false ;

            second = second->next ; 
            first = first->next ;
        }
        return true ;
    }