/*
PROBLEM STATEMENT
Given a non-empty integer array arr[]. Your task is to find and return the top k elements which have the highest frequency in the array.

Note: If two numbers have the same frequency, the larger number should be given the higher priority.

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std ;

void merge(vector<vector<int>>& nums , int st , int mid , int end){
        int t = st , j = mid+1 ;
        vector<vector<int>> temp ;
        while(t<=mid  && j <= end){
            if(nums[t][1]<nums[j][1]){
                temp.push_back(nums[t++]);
            }else if(nums[t][1]>nums[j][1]){
                temp.push_back(nums[j++]);
            }else{
                if(nums[t][0] < nums[j][0]) temp.push_back(nums[t++]);
                else temp.push_back(nums[j++]);

            }
        }
        while(t<= mid){
            temp.push_back(nums[t++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        
        for(int i = 0 ; i < (int)temp.size() ;  i++){
            nums[i+st] = temp[i];
        }
    }
    
    void merge_sort(vector<vector<int>> &nums , int st , int end){
        if(st<end){
            int mid = st + (end-st)/2;
            merge_sort(nums , st , mid);
            merge_sort(nums, mid+1 , end);
            
            merge(nums , st , mid , end);
        }
    }
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        map<int, int>m ;
        for(int i = 0 ; i < n ; i++){
            m[arr[i]]++;
        }
        vector<vector<int>>freq ;
        for(auto& i : m){
            freq.push_back({i.first , i.second});
        }
        merge_sort(freq , 0 , freq.size()-1);
        
        vector<int>ans ;
        for(int i = freq.size()-1 ; k--  && i >= 0; i--){
            ans.push_back(freq[i][0]);
        }
        return ans ;
    }

    int main(){
        vector<int>nums = {3, 1, 4, 4, 5, 2, 6, 1} ;
        vector<int>ans  = topKFreq(nums , 2);

        for(auto i : ans) cout<<i<<' ';
        cout<<endl ;
        return 0 ;
    }