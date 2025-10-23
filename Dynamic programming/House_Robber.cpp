/*
    PROBLEM STATEMENT
    Given an array arr containing positive integers. Find the maximum sum of elements of any possible subsequence such that
    no two numbers in the subsequence should be adjacent in array arr[].

        OR(house robber)
        You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
        the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
        and it will automatically contact the police if two adjacent houses were broken into on the same night.
        Given an integer array nums representing the amount of money of each house, 
        return the maximum amount of money you can rob tonight without alerting the police.
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std ;

// int help(int n , vector<int>& nums , int pos , int sum){//recursion without any memoizations
//     if(pos == n-1) return ( sum + nums[n-1] );
//     else if(pos >= n) return 0 ;

//     return max(help(n , nums, pos+1 , sum) , help(n , nums , pos+2 , sum+nums[pos]));
// }

int help(int n , vector<int> &nums , int pos , vector<int> &arr){
        if(pos>= n) return 0 ;
        if(arr[pos] != -1) return arr[pos];

        int inlcude = nums[pos] + help(n , nums , pos+2 , arr);
        int exclude = help(n , nums , pos+1 , arr);

        return arr[pos] = max(inlcude,exclude);
    }
    int MaxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n , -1) ;
        return help(n , nums , 0 , arr);
    }

// ***** LETS TRY TO DO TABULATION****** // MAKES THE THE ALGO FREE OF STACK SPACE

int House_robber(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n , -1) ;
    dp[0] = nums[0];
    for(int i = 1 ; i < n ; i++){
        int pick = INT_MIN ;
        if(i > 1){
            pick = dp[i-1] + nums[i];
        }
        int notpick = 0 + dp[i-1];

        dp[i] = max(pick , notpick) ;
    }

    return dp[n-1] ;
}

// ****** SPACE OPTIMIZATION ******

int House_robber_with_space_optimization(vector<int> &nums){
    int prev2 = 0 , prev1 ;
    prev1 = nums[0] ;

    for(int i = 1 ; i < nums.size() ; i++){
        int take = prev2 + nums[i];
        int notTake = prev1  + 0 ;

        prev2 = prev1 ;
        prev1 = max(take , notTake);
    }

    return prev1 ;
}