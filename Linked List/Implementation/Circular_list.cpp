#include<iostream>

using namespace std ;

class Node{
    public:
    int val ;
    Node* next ;
    Node(int val){
        this->val = val ;
        next = NULL ;
    }
};

class CircularList{
    Node *tail ;
    public:
    CircularList(){
        tail = NULL ;
    }

    void push_front(int val){

        Node *newnode = new Node(val);
        if(tail == NULL){
            tail = newnode ;
            tail->next = newnode ;
        }else{
            newnode->next = tail->next  ;
            tail->next = newnode ;
        }
    }

    void push_back(int val){
        Node *newnode = new Node(val);
        if(tail == NULL){
            tail = newnode ;
            tail->next = newnode ;
        }else{
            newnode->next = tail->next ;
            tail->next = newnode ;
            tail = newnode ;
        }
    }

    void pop_front(){
        if(tail == NULL) return ;

        Node *temp = tail->next ;

        if(tail == temp ){//only 1 node
            tail = NULL ;
        }else{
            tail->next = temp->next ;
        }

        delete(temp);
    }

    void pop_back(){
        if(tail == NULL) return; 
        
        Node *temp = tail->next ;
        if(tail == temp){// to handle a single node list
            tail = NULL ;
            delete(temp);
            return ;
        }
        while(temp->next != tail){
            temp = temp->next ;
        }
        temp->next = tail->next ;
        delete(tail);

        tail = temp ;
    }
};