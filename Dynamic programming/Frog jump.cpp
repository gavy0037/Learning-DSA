/*
    PROBLEM STATEMENT

Given an integer array height[] where height[i] represents the height of the i-th stair, 
a frog starts from the first stair and wants to reach the top. 
From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
The cost of a jump is the absolute difference in height between the two stairs.
Determine the minimum total cost required for the frog to reach the top

 */

#include<iostream>
#include<vector>

using namespace std ;

    int abs(int a){
        return a< 0 ? -a : a ;
    }
    int minCost(vector<int>& nums) {
        // Code here
        int n = nums.size();
        int arr[n] ;
        
        if(n == 1) return 0 ;
        else if(n == 2) return abs(nums[0]-nums[1]);
        
        arr[n-1]= 0 ;//[Using bottom up aproach that is very much similar to this] we can use two variables here prev2(for arr[i-2]) and prev1(for arr[i-1]) 
        //because for arr[i] we need only arr[i-1] and arr[i-2] after the loop we can just print the ans(taken as another variable)
        arr[n-2] = abs(nums[n-2]-nums[n-1]);
        for(int i = n-3 ; i >=0; i--){
            if(i+1 < n ){
                arr[i] = abs(nums[i]-nums[i+1]) + arr[i+1] ;
            }
            if(i+2 < n ){
                arr[i] = min(arr[i],abs(nums[i]-nums[i+2]) + arr[i+2]);
            }
        }
        
        return arr[0];
    }