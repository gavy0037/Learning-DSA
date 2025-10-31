#include<iostream>

using namespace std ;

class Node{
    public:
    int val ;
    Node *next , *prev ;
    Node(int val){
        this->val = val ;
        next = prev = NULL ;
    }
};

class DLL{
    Node *head , *tail ;
    public:

    DLL(){
        head = tail = NULL ;
    }
    void push_front(int val){
        Node *newnode = new Node(val);
        if(head == NULL) tail = head = newnode ;
        else{
            newnode->next = head ;
            head->prev = newnode ;
            head = newnode ;
        }
    }
    void push_back(int val){
        Node *newnode = new Node(val);
        if(head == NULL){
            tail = head = newnode ;
        }else{
            tail->next = newnode ;
            newnode->prev = tail ;
            tail = newnode ;
        }
    }
    void pop_front(){
        if(head == NULL) return ;
        if(head->next == NULL){
             head = NULL ;
             return ;
        }
        Node *temp = head->next ;
        head->next = NULL ;
        temp->prev = NULL ;
        delete(head);

        head = temp ;
    }

    void pop_front(){
        if(head == NULL){
            return ;
        }
        Node* temp = head ;

        head = head->next ;
        if(head != NULL){
            head->prev = NULL ;
        }

        temp->next = NULL ;
        delete(temp);
    }

    void pop_back(){
        if(head == NULL) return ;
        
        Node *temp = tail ;

        tail = tail->prev ;
        if(tail != NULL){
            tail->next = NULL ;
        }
        temp->prev = NULL ;
        delete(temp);
    }
};