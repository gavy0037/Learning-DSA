#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std ;


vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n , -1);
        stack<int>stk ;
        for(int i = 0 ; i < n; i++){
            while(stk.size() > 0 && stk.top() >= arr[i]){
                stk.pop();
            }
            if(stk.size() != 0) ans[i] = stk.top();
            stk.push(arr[i]);
        }
        return ans ;
    }