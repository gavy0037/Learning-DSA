/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

#include<iostream>
#include<vector>

using namespace std ;


int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size() , n = matrix[0].size();
    vector<vector<int>>dp(m , vector<int>(n , 0));
    int max_side = 0 ; 

    // base cases
    for(int i = 0 ; i < m ; i++){ 
        dp[i][0] = matrix[i][0] - '0';
        max_side = max(max_side , dp[i][0]);
    }
    for(int i = 0 ; i < n ; i++){ 
        dp[0][i] = matrix[0][i] - '0';
        max_side = max(max_side , dp[0][i]);
    }


    for(int i = 1; i < m ; i++){
        for(int j = 1 ;  j < n ; j++){
            if(matrix[i][j] == '0') dp[i][j] = 0 ;
            else dp[i][j] = 1+min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1]));

            max_side = max(max_side , dp[i][j]);
        }
    }

    return max_side*max_side ;
}