/*
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice.
Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. 
Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, 
determine the maximum total merit points Geek can achieve .
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

//                                  *********** RECURSIVE DP **************

/* int helper(vector<vector<int>> &nums  , int row  , int col , vector<vector<int>>&dp){//col cant bee taken in this turen
        if(row == nums.size()-1){
            int m = INT_MIN ;
            for(int i = 0 ; i < 3 ; i++){
                if(i != col) m = max(m , nums[row][i]);
            }
            return m ;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int ans = INT_MIN ;
        for(int i = 0 ; i < 3 ; i++){
            if(i != col){
                ans = max(ans , nums[row][i] + helper(nums, row+1 , i , dp));
            }
        }
        return dp[row][col] = ans ;
    }
    int maximumPoints(vector<vector<int>>& nums) {
        // Code here
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        if(nums.size() == 1){
            int a = 0 ;
            for(int i = 0 ; i < 3 ; i++){
                a = max(a , nums[0][i]);
            }
            return a ;
        }
        for(int i = 0 ; i < 3 ; i++) dp[0][i] = nums[0][i] + helper(nums , 1 , i , dp);
        return max(dp[0][0] , max(dp[0][1] ,dp[0][2] ));
    } */

    int maximumPoints(vector<vector<int>>& nums) {  // MEMORY EFFECIENT
        // Code here
        int n = nums.size();
        vector<vector<int>>dp(2 , vector<int>(3 , -1));
        dp[1] = nums[n-1] ;
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < 3 ; j++){
                int m = 0 ;
                for(int a = 0 ; a < 3 ; a++){
                    if(a != j) m = max(dp[1][a] , m);
                }
                dp[0][j] = nums[i][j] + m ;
            }
            dp[1] = dp[0];
        }
        return max(dp[0][0] , max(dp[0][1] ,dp[0][2] ));
    }

int main(){
    vector<vector<int>> nums = {{1,2,5},
                                {3,1,1,},
                                {3,2,3}};
    cout<<maximumPoints(nums);

    return 0 ;
}   