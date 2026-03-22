/*
        LEETCODE 3583

    You are given an integer array nums.
    A special triplet is defined as a triplet of indices (i, j, k) such that:

    0 <= i < j < k < n, where n = nums.length
    nums[i] == nums[j] * 2
    nums[k] == nums[j] * 2
    Return the total number of special triplets in the array.
    Since the answer may be large, return it modulo 109 + 7.
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std ;

int specialTriplets(vector<int>& nums) {
    // if the same element exists on some index, and then find number of half elements between them, now skip that element and add the answer of that last occurence of that same element.
    map<int , int> global_freq , left_freq ;
    long long ans = 0 ;
    for(auto i : nums) global_freq[i]++;
    for(int i = 0 ;i < nums.size() ; i++){
        long long leftCnt = left_freq[2*nums[i]] ; 
        left_freq[nums[i]]++;
        
        long long rightCnt = global_freq[2*nums[i]] - left_freq[2*nums[i]];

        ans = (ans+leftCnt*rightCnt)%1000000007 ;
    }
    return ans ;
}