#include<iostream>
#include<vector>
#include<list>
#include<stack>//for stack

using namespace std ;

//stack implementation using vectors
class Stack_using_vector {
    vector<int>v ;
public: 
    void push_back(int val){//O(1)
        v.push_back(val);
    }

    void pop(){//O(1)
        v.pop_back();
    }

    int top(){//O(1)
        return v[v.size()-1] ;
    }

    bool empty(){
        return v.size() == 0 ;
    }
};

//for implementation using linked list we make the top of the linked list and the top of the stack equivalent

class Stack_using_ll{//ll -> linked list using the in-built LIST library 
    list<int>ll ;

public: 
    void push(int val){
        ll.push_front(val);
    }   
    void pop(){
        ll.pop_front();
    } 
    int top(){
        return ll.front();//return the val at the head of the linked list
    }

    bool empty(){
        return ll.size() == 0 ;
    }
};

int main(){
    // to make a stack
    stack<int>s ;
    //funtions -> pop , push , top , empty
}