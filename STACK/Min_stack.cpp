#include<iostream>
#include<stack>
#include<climits>

using namespace std ;

class MinStack1 {
public:
    stack<int>normal_stack , min_element_stack;
    int mine = INT_MAX ;
    MinStack1() {
        
    }
    
    void push(int val) {
        if(min_element_stack.size() == 0 || val <= mine){
            min_element_stack.push(val);
            mine = val ;
        }
        normal_stack.push(val);
    }
    
    void pop() {
        if(normal_stack.top() == min_element_stack.top()){
            min_element_stack.pop();
            if(min_element_stack.size() > 0) mine = min_element_stack.top();
            else mine = INT_MAX ;
        }
        normal_stack.pop();
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return min_element_stack.top() ;
    }
};


// SOLUTION 2


class MinStack2 {
public:
    stack<pair<int,int>>stk ;
    MinStack2(){}
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val , val});
        }else{
            int minval = min(val , stk.top().second);
            stk.push({val , minval});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first ;
    }
    
    int getMin() {
        return stk.top().second ;
    }
};

class MinStack3{
    stack<int>stk ;
    long long min_val ;
    MinStack3(){

    }

    void push(int val){
        if(stk.empty()){
            stk.push(val);
            min_val = val ;
        }else{
            if(val < min_val){
                stk.push((long long)2*val - min_val);
                min_val = val ;
            }else stk.push(val);
        }
    }

    void pop(){
        if(stk.top() < min_val){
            min_val = 2*min_val - stk.top();
        }
        stk.pop();
    }

    int top(){
        if(stk.top() < min_val) return min_val ;

        return stk.top();
    }

    int getMin(){
        return min_val ;
    }
};