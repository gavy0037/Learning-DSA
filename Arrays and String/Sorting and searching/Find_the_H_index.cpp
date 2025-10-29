/*
    PROBLEM STATEMENT
    You are given an array citations[], where each element citations[i] represents the number of citations received 
    by the ith paper of a researcher. You have to calculate the researcher’s H-index.
    The H-index is defined as the maximum value H, such that the researcher has published at least H papers, 
    and all those papers have citation value greater than or equal to H    
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int hIndex(vector<int>& nums) {
        // code here
        sort(nums.begin(),nums.end());
        int ans = nums.size();
        while(ans){
            int f = 0 ;
            int st = 0 , end = nums.size()-1 ;
            while(st<=end){
                int mid = st + (end-st)/2 ;
                if(nums[mid] >= ans){
                    f+=(end-mid+1);
                    end = mid-1 ;
                }
                else{
                    st = mid+1 ;
                }
            }
            printf("%d %d\n",ans , f);
            if(f>=ans) return ans ;
            else ans-- ;
        }
        return ans ;
    }

    int main(){
        vector<int> nums = {13,14,7,9,7,16,15,10,6,5,11,8,7,5,6};//5 5 6 6 7 7 7 9 10 11 13 14 15 16
        cout<<hIndex(nums);
    }

