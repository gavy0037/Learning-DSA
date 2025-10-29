/*
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1, 3], [2, 4], [6, 8], [9, 10]]
Output: [[1, 4], [6, 8], [9, 10]]
Explanation: In the given intervals we have only two overlapping intervals here, 
[1, 3] and [2, 4] which on merging will become [1, 4]. Therefore we will return [[1, 4], [6, 8], [9, 10]].

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

    bool ifoverlap(vector<int> nums1 , vector<int>nums2){
        // this function does not check universally if two intervals overlapp; only check for a particular order
        //if you want to make it universal( i.e for both directions just add the corresponding statement for the opposite pair in return statement)
        //for this case it is not required
        return nums1[1] >= nums2[0] ;
    }
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> ans ;
        sort(arr.begin() ,arr.end());
        vector<int>temp = arr[0];
        for(int i = 1 ; i < arr.size() ; i++){
            if(ifoverlap(temp ,arr[i])){
                temp[1] = max(arr[i][1] , temp[1]);
            }else{
                ans.push_back(temp);
                temp = arr[i] ;
            }
        }
        ans.push_back(temp);
        return ans ;
    }