/*
PROBLEM STATEMENT

Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent

of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:

    Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
    The subarrays must be adjacent, meaning b = a + k.

Return the maximum possible value of k.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

#include<iostream>
#include<vector>

using namespace std ;

    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0 , ct = 1 , prect = 0 ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]>nums[i-1]){
                ct++;
            }else{
                prect = ct ;
                ct = 1 ;
            }
            ans = max(ans,min(prect , ct));
            ans = max(ans , ct/2);
        }
        return max(ans,1) ;
    }
