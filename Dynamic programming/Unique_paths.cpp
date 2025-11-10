/*
    Given m and n 
    return the no of possible paths int a grid of size m*n from 0,0 to m-1,n-1 
    You can move only down and right

*/

#include<iostream>
#include<vector>

using namespace std ;

/************* RECURSIVE DP(with extra stack space of m + n) *************/

int helper(int m , int n , vector<vector<int>>&nums){
        if(m == 0 && n == 0) return 1 ;
        
        if(nums[m][n] != -1) return nums[m][n];

        int up = (m > 0 ? helper(m-1 , n , nums) : 0) ;
        int left = (n > 0 ? helper(m , n-1 , nums) : 0) ;
        
        return nums[m][n] = up + left ;
}

/************ TABULATION ( no stack space needed ) **************/

int uniquePaths(int m, int n) {
        vector<vector<int>>dp( m , vector<int>(n , 0));
        dp[m-1][n-1] = 1 ;// dp stores the ways of reaching the (m-1 ,n-1) cell 

        //every cell uses the below cell or the right cell to get the paths(i am doing bottom up)
        //so the direction of looping becomes row wise: up and coloumn wise : lefT

        for(int i = m-1 ; i >= 0;  i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i != m-1 || j != n-1){
                    int right = ( j < n-1 ? dp[i][j+1] : 0);
                    int down = ( i < m-1 ? dp[i+1][j] : 0);
                    dp[i][j] = right + down ;
                }
            }
        }   
        return dp[0][0];
    }

/*************** SPACE OPTIMIZATION ***************/

int uniquePaths(int m, int n) {
        //every cell uses the below cell or the right cell to get the paths(i am doing bottom up)
        //so the direction of looping becomes rowwise: up and coloumn wise : leftwards
        vector<int>down(n , 1) ;
        for(int i = m-2 ; i >= 0;  i--){
            int right = 0 ;
            for(int j = n-1 ; j >= 0 ; j--){
                down[j] += right ;
                right = down[j];
            }    
        }   
        return down[0] ;
    }