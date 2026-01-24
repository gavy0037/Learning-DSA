/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
*/


#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> nse(vector<int>& arr){
    stack<int>stk ;
    int n = arr.size();
    vector<int>ans(n , n);
    for(int i = n-1 ;i >= 0 ; i--){
        while(!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();

        if(!stk.empty()) ans[i] = stk.top();

        stk.push(i);
    }
    return ans;
}

vector<int> psee(vector<int> &arr){
    stack<int>stk ;
    int n = arr.size();
    vector<int>ans(n , -1);

    for(int i = 0 ;i < n ; i++){
        while(!stk.empty() && arr[i] < arr[stk.top()]) stk.pop();

        if(!stk.empty()) ans[i] = stk.top();
        stk.push(i);
    }

    return ans ;
}
int sumSubarrayMins(vector<int>& arr) {
    int sum = 0 , n = arr.size();
    vector<int> left_smaller = psee(arr) , right_smaller = nse(arr);
    for(int i = 0 ;i < n; i++){
        int left = i-left_smaller[i] , right = right_smaller[i]-i ;

        long long freq = left*right ;

        int val = (freq*arr[i])%MOD ;
        sum = (sum+val)%MOD;
    }

    return sum; 
}

int main() {

    
    return 0;
}