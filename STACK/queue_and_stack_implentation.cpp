#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std ;

#define SIZE 10

// using arrays

// STACK : LIFO
// QUEUE : FIFO
/* Basic functions for stack and queue:
    1. push
    2. pop
    3. top
    4. size
*/

class stack_using_array{
    public :
    //assuming the max size given is 10
    int t = -1 , stack[SIZE]; // t is pointer to top of stack
    // No need for constructors
    // for all functions assuming that we still have space in stack
    void push(int val){
        t++;
        stack[t] = val ;
    }
    void pop(){ t-- ;}
    int top(){ return stack[t];}
    int size(){ return t+1 ;}
};

class node{
    public:

    int val ;
    node *next ;

    node(int val){
        this->val = val ;
        next = NULL ;
    }
};

class stack_using_ll{
    node *head ; // head will be top
    int curr_size = 0 ;
    public:
        stack_using_ll(){
            head = NULL ;
        }
        
        void push(int val){
            curr_size++;
            node *newnode = new node(val);
            if(head == NULL){
                head = newnode ;
                return ;
            }
            newnode->next = head ;
            head = newnode ;
        }
        void pop(){// it is pop front for O(1)
            if(head == NULL) return ;
            if(head->next == NULL){
                delete(head);
                curr_size--;
                head = NULL ;
                return; 
            }
            node *temp = head ;
            head = head->next ;
            curr_size--;
            delete(temp);
        }
        int top(){
            if(head == NULL){
                cout<<"Empty stack\n";
                return -1 ;
            }
            return head->val ;
        }
        int size(){
            return curr_size ;
        }
        bool empty(){
            return head == NULL ;
        }
};

class queue_using_array{
    int curr_size = 0 , st = -1 , end = -1 , queue[SIZE];
    public:
        // no constructor is required
        void push(int val){
            if(curr_size == 0){
                st = 0 ;
            }
            end = (end+1)%SIZE ;
            queue[end] = val ;
            curr_size++;
        }
        int pop(){
            int popped ;
            if(curr_size == 0){
                return ;
            }
            else if(curr_size == 1){
                popped = queue[st];
                end = st = -1 ;
            }else{
                popped = queue[st];
                st = (st+1)%SIZE ;
            }
            curr_size-- ;
            return popped ;
        }
        int top(){
            if(curr_size == 0){
                cout<<"Size is zero\n";
                return -1 ;
            }
            return queue[st];
        }

        int size(){return curr_size ;}
};

class queue_using_ll{
    node *head , *tail ;
    int size = 0 ;
    public:
        queue_using_ll(){
            head = tail = NULL ;
        }

        void push(int val){ // this is push back
            size++;
            node* newnode = new node(val);
            if(head == NULL) head = tail = newnode ;
            else{
                tail->next = newnode ;
                tail = newnode ;
            }
        }

        int pop(){ // this is pop front
            
            if(head == NULL){
                cout<<"Queue is empty\n";
                return -1 ;
            }else if(head->next == NULL){
                size--;
                int val = head->val ;
                delete(head);
                head = tail = NULL ;
                return val ;
            }else{
                size--;
                int val = head->val ;
                node *temp = head ;
                head = head->next ;
                delete(temp);

                return val ;
            }
            return -1 ;// this will never be returned
        }

        int top(){ 
            if(head == NULL){
                cout<<"Queue is empty\n";
                return -1 ;
            }    
            return head->val ;
        }
        int size(){return size ;}
};

// stack using queue

class stack_using_queue{
    public:
        queue<int>q ;
        void push(int val){
            int size = q.size();
            q.push(val);
            for(int i = 1 ; i < size ; i++){
                q.push(q.front());
                q.pop();
            }
        }
        void pop(){ q.pop(); }

        int top(){return q.front();}
};

class queue_using_stack{// done using 2 stacks
    public:
        stack<int> s1 , s2 ;
        
        void push(int val){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(s2.size()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        int front(){ return s1.top();}
        void pop(){ s1.pop(); }
};

int main(){

    return 0 ;
}