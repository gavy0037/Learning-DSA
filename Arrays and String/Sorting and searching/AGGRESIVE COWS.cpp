/*You are given N stalls located along a straight line at positions x1, x2, ..., xN, and you are asked to place C cows in these stalls.
The goal is to maximize the minimum distance between any two cows.

Input:

The first line contains two integers:
N — the number of stalls,
C — the number of cows.

The next line contains N integers — the positions of the stalls.

Output:

Output a single integer — the largest minimum distance possible between any two cows.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 bool valid(vector<int> &nums , int cows , int mindistance){
        int curr_cows = 1 , lastpos = 0  ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]-nums[lastpos] >= mindistance){
                curr_cows++;
                lastpos = i ;
            }
        }
        if(cows <= curr_cows) return true ;
        
        return false ;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        // code here
        sort(nums.begin() , nums.end());
        int n = nums.size()-1 ;
        int maxdif = nums[n]-nums[0] , ans = -1 ;
        int st = 1 , end = maxdif ;
        
        while(st<=end){
            int mid = st+(end-st)/2 ;
            if(valid(nums , k , mid )){
                ans = mid ;
                st = mid+1 ;
            }else{
                end = mid-1 ;
            }
        }
        return ans ;
    }

int main(){
    vector<int>nums = {6,4,3,16,20,7,18,10};
    int cows = 5 ;
    cout<<aggressiveCows(nums , cows);
}