/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 #include<iostream>

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2 ;
        if(list2 == NULL) return list1 ;
        
        ListNode *head ,*tail;
        head = tail = NULL ;
        while(list1 != NULL && list2!= NULL){
            ListNode *newnode = new ListNode ;
            newnode->next = NULL ;
            if(list1->val < list2->val){
                newnode->val = list1->val ;
                list1 = list1->next ;
            }else{
                newnode->val = list2->val ;
                list2 = list2->next ;
            }
            if(head == NULL) head = tail = newnode ;
            else{
                tail->next = newnode ;
                tail = newnode;
            }
        }
        while(list1 != NULL){
            ListNode *newnode = new ListNode ;
            newnode->next = NULL ;
            newnode->val = list1->val ;
            list1 = list1->next ;
            
            if(head == NULL) head = tail = newnode ;
            else{
                tail->next = newnode ;
                tail = newnode;
            }
        }
        while(list2 != NULL){
            ListNode *newnode = new ListNode ;
            newnode->next = NULL ;
            newnode->val = list2->val ;
            list2 = list2->next ;
            
            if(head == NULL) head = tail = newnode ;
            else{
                tail->next = newnode ;
                tail = newnode;
            }
        }
        return head ;
    }