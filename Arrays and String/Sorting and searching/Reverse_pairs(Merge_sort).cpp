/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:
    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].
 
*/

#include<iostream>
#include<vector>

using namespace std ;

int merge(vector<int>&nums , int st , int mid , int end){
    int i = st , j = mid+1 ;
    int count = 0 ;
    vector<int>temp ;
    for(int a = st ; a <= mid ; a++){
        while(j <= end && 2*(long long)nums[j] < nums[a]) j++;
        count+=(j-mid-1) ;
    }
    j = mid+1  ;
    while( i <= mid && j <= end){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(nums[i++]);
    }
    while(j <=end){
        temp.push_back(nums[j++]);
    }
    for(int i = 0 ; i < end-st+1 ; i++){
        nums[i+st] = temp[i];
    }
    return count ;
}

int sort(vector<int>& nums , int st , int end){
    if(st >= end) return 0 ;
    
    int mid = st+(end-st)/2;
    return (sort(nums , st , mid) + sort(nums , mid+1 , end) + merge(nums , st , mid , end));

}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return sort(nums , 0 , n-1);
}