/*
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include<iostream>
#include<vector>

using namespace std ;

 int merge(vector<int>&nums , int st , int mid , int end){//return count as well as merges the two lists
        int i = st , j = mid+1 ;
        int count = 0 ;
        vector<int>temp ;
        while( i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else{
                count+=(mid-i+1);
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


    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return sort(arr , 0 , n-1);
    }