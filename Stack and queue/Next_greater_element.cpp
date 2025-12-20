/*
You are given an array arr[] of integers, the task is to find the next greater element for 
each element of the array in order of their appearance in the array. Next greater element 
of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

vector<int> nextLargerElement(vector<int>& arr) {
    // code here
    int n = arr.size();
    stack<int>stk ;
    vector<int>ans(n,-1);
    for(int i = 0 ;  i< n; i++){
        while(stk.size() > 0 && arr[stk.top()]<arr[i]){
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(arr[i]);
    }
    return ans ;
}

void print_vector(vector<int>nums){
    for(int i = 0 ; i < nums.size() ; i++) cout<<nums[i]<<' ';
    cout<<endl ;
}

int main(){
    vector<int>arr = {1,3,2,4};
    vector<int>ans = nextLargerElement(arr);
    print_vector(ans);

    return 0 ;
}