#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isvalid(int mindistance,vector<int>nums,int cows){
    int cow = 1 , lastpos = 0 ;
    for(int i = 1 ;i<nums.size() ; i++){
        if(nums[i]-nums[lastpos] >= mindistance){
            lastpos = i ;
            cow++;
        }
        if(cow == cows){
            return true;
        }
    }
    return false ;
}

int largestmindistance(int cows , vector<int>& nums){

    int n =nums.size();
    sort(nums.begin(),nums.end());
    int maxdif = nums[n-1]-nums[0];
    int ans = -1 ;
    int st = 1 , end  = maxdif;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isvalid(mid,nums,cows)){
            st = mid+1 ;
            ans = mid; 
        }else{
            end = mid-1;
        }
    }
return ans;
}

int main(){
    vector<int>nums = {1,2,4,8,9};
    int cows = 3 ;
    cout<<largestmindistance(cows,nums);
}