/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false
*/

#include<bits/stdc++.h>

using namespace std ;



bool find132pattern(vector<int>& nums) {
    stack<int>st ;
    int k = INT_MIN ;

    for(int i = nums.size()-1 ; i >= 0 ; i--){
        if(nums[i] < k) return true ;

        while(!st.empty() && st.top() < nums[i]){
            k = max(k , st.top());
            st.pop();
        }

        st.push(nums[i]);
    }

    return false ;
}