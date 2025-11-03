/*

SORT the list without using extra space using merge sort

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

    ListNode* mid(ListNode *head){
        if(head == NULL || head->next == NULL) return head ;
        ListNode *slow = head , *fast = head->next ;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next ;

            slow = slow->next ;
        }
        return slow ;
    }

    ListNode *merge(ListNode *head1 , ListNode *head2){
        ListNode *dummy = new ListNode(-1) ;
        ListNode *temp = dummy ;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                temp->next = head1 ;
                temp = temp->next ;    
                
                head1 = head1->next ;
            }else{
                temp->next = head2 ;
                temp = temp->next ;

                head2 = head2->next ;
            }
        }
        if(head1) temp->next = head1 ;
        else if(head2) temp->next = head2 ;
        return dummy->next ;
    }

    ListNode* sort(ListNode *head){
        if(head == NULL || head->next == NULL) return head ;

        ListNode *middleNode = mid(head);
        ListNode *right = middleNode->next ;
        middleNode->next = NULL ;
        head = sort(head);//do not mistake it as array as the changes are taking without passing by refrence so you need to assign the values to the list again 
        // only sort(head) won't work here
        right = sort(right);

        return merge(head , right);
    }



    ListNode* sortList(ListNode* head) {
        return sort(head);
    }