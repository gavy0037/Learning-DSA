/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
*/

#include<iostream>
#include<vector>

using namespace std ;


void merge(vector<vector<int>> &arr , int st , int mid ,int end , vector<int> &ans){
    int i = st , j = mid+1 , count_smaller = 0  , idx = 0;
    vector<vector<int>>temp(end-st+1 , vector<int>(2));
    while( i <= mid && j <= end){
            if(arr[i][0]<=arr[j][0]){
            temp[idx][0] = arr[i][0];
            temp[idx][1] = arr[i][1];
            ans[arr[i][1]]+=count_smaller ;
            idx++;i++;
        }else{
            count_smaller++;

            temp[idx][0] = arr[j][0];
            temp[idx][1] = arr[j][1];

            idx++;j++;
        }
    }

    while(i <= mid){
        ans[arr[i][1]]+=count_smaller ;
        temp[idx++] = arr[i++];
    }
    while(j <= end){
        temp[idx++] = arr[j++];
    }

    for(int i = 0 ; i < end-st+1 ; i++) arr[i+st] = temp[i];
}

void count(vector<vector<int>> &arr , int st, int end , vector<int>& ans){
    if(st<end){
        int mid = st + (end-st)/2 ;
        count(arr ,st , mid , ans);
        count(arr , mid+1 ,end, ans);
        merge(arr , st , mid , end , ans);
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>arr_pos ;
    for(int i = 0 ;i < n ; i++){
        arr_pos.push_back({nums[i] , i});
    }
    vector<int>ans(n) ;
    count(arr_pos , 0 , n-1 , ans);

    return ans ;
}


/*              Using BST(But this may cause TLE so above solution is recommended)                  */

