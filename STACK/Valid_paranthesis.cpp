/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([])"
Output: true

Example 5:

Input: s = "([)]"
Output: false  */

#include<iostream>
#include<string>
#include<stack>

using namespace std ;

bool isvalid(char a , char b){
        if(a == '(') return b == ')';

        if(a == '{') return b == '}';

        if(a == '[') return b == ']' ;

        return false ;
    }
    bool isValid(string s) {
        stack<char>stack ;
        if(s.length() == 1) return false ;
        for(int i = 0 ; i < s.length() ; i++){
            if(!stack.empty() && isvalid(stack.top() , s[i])){
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }
        return stack.size() == 0 ;
    }