/*

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, 
return the number of nodes in the loop, otherwise return 0.

*/

#include<iostream>
#include<unordered_set>

using namespace std ;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

int lengthOfLoop(Node *head) {
        // code here
        unordered_set<Node*>s ;
        for(Node* temp = head ; temp != NULL ; temp = temp->next){
            s.insert(temp);
            if(s.find(temp->next) != s.end()){
                int ans = 0 ;
                Node* i = temp ;
                do {
                    ans++;
                    i = i->next ;
                }while(i != temp);
                return ans ;
            }
        }
        return  0 ;
    }