#include<iostream>

using namespace std ;

class Node{
public :
    int data ;
    Node *next ;//stores the address of next class
    Node(int data){//constructor for node
        this->data = data;
        next = NULL;
    }
};

class List{
Node *head ;
Node *tail ;
public :
    List(){
        head = NULL ;
        tail = NULL ;
    }
    void push_front(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode ;
            return ;
        }else{
            newNode -> next = head ;
            head = newNode ;
            return ;
        }
    }
    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL){//convention to check if the list is empty or not
            head = tail = newNode ;
            return ;
        }else{
            // newnode -> next = tail;
            tail->next = newNode ;
            tail = newNode ;
            return ;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"There is nothing in this list"<<endl;
            return ;
        }else{
            Node *temp = head ;
            head = head->next ;
            temp->next = NULL ;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL){
            cout<<"There is nothing in this list"<<endl;
            return ;
        }else{
            Node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            // tail = temp;
            temp->next = NULL;
            delete tail ;
            tail = temp ;
            return;
        }
    }

    void insert(int val , int pos){
        Node* temp = head ;
        if(pos<0){
            cout<<"INVALID POSITION ENTERED\n";
            return ;
        }else if(pos == 0){
            push_front(val);
            return ;
        }
        for(int i = 0 ; i < pos-1 ; i++){//to get the node which will form link with newnode
            if(temp == NULL){//or the condition is temp == tail
                cout<<"INVALID POSITION ENTERED\n";
                return ;
            }
            temp = temp->next ;

        }
        Node* newnode = new Node(val);
        newnode->next = temp->next ;//makes the link of the new node with the next node before its address is lost
        //handles the case for push_back
        temp->next = newnode ;
    }

    void search(int val){
        Node* temp = head ;
        int a = 0 ;
        while(temp != NULL){
            if(temp->data == val){
                cout<<"found "<<val<<" at index: "<<a<<endl;
                return ;
            }
            temp = temp->next ;
            a++;
        }
        cout<<"not found\n";
        return ;
    }

    void print(){
        for(Node *i = head ; i != NULL ; i = i->next ){//till tail ponter because then it will point to null
            cout<<i->data <<"->";
        }
        cout<<"NULL"<<endl;
        return ;
    }
};

int main(){
    List ll ;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.insert(4,1);
    ll.search(1);
    return 0 ;
}
//3 2 1 4