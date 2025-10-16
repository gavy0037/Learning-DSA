#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std ;


    void nextPermutation(vector<int>& nums) {
        // code here
        int pivot = -1 ;
        for(int i =nums.size()-2 ; i >= 0 ; i--){//got the index where we hVE TO swap
            if(nums[i]<nums[i+1]){
                pivot = i ;
            }
        }

        if(pivot == -1){
        int st = 0,end = nums.size()-1 ;
        while(st<end){
            swap(nums[st],nums[end]);
            st++;end--;
        }
        }else{
            for(int i = nums.size()-1 ; i >pivot;  i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break ;
            }
        }
        int st = pivot+1,end = nums.size()-1 ;
        while(st<end){
            swap(nums[st],nums[end]);
            st++;end--;
        }
        }
    }


    int main(){
        vector<int>nums = {1,2,3};
        nextPermutation(nums);
        for(int i = 0 ; i < nums.size() ; i++){
            cout<<nums[i]<<" ";
        } 
        return 0 ;
    }