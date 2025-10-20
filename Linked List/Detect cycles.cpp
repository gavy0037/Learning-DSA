/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

*/

#include<iostream>


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL ){
            return false ;
        }
        ListNode *slow = head , *fast = head ;

        while(fast != NULL && fast->next != NULL){
                slow = slow->next ;
                fast = fast->next->next ;
            
            if(slow == fast){
                return true ;
            }
        }
        return false ;
    }

/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

ListNode *detectCycle(ListNode *head) {//   RETURN THE POINTER OF BEGGENING OF THE CYCLE
        ListNode *slow , *fast ;
        fast = slow = head ;
        bool iscycle = false ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;

            if(slow == fast){
                iscycle = true ;
                break ;
            }
        }
        if(iscycle == false) return NULL ;
        slow = head ;
        while(slow != fast){
            slow = slow->next ;
            fast = fast->next ;
        }
        return slow ;
    }