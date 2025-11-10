/*
You are given a matrix mat[][] of size n x m, where each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from the top left cell of the matrix to the bottom right cell.
From a cell (i, j), you can only move to cell (i+1, j) or (i, j+1).
*/

#include<iostream>
#include<vector>

using namespace std ;


int help(vector<vector<int>> &mat , int sum , int k , int row, int col , vector<vector<vector<int>>>& dp){//using recursion and dp
        if(row == mat.size()-1 && col == mat[0].size()-1){
            if(sum == k) return 1 ;
            else return 0;
        }
        if(sum>k) return 0 ;
        
        if(dp[row][col][sum] != -1) return dp[row][col][sum] ;
        
        int right = col < mat[0].size()-1 ? help(mat , sum+mat[row][col+1] , k , row , col+1 , dp) : 0 ;
        int down = row< mat.size()-1 ? help(mat , sum+mat[row+1][col] , k , row+1 , col , dp) : 0 ;
        
        return dp[row][col][sum] = right + down ;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here

        vector<vector<vector<int>>>dp(mat.size() , vector<vector<int>>(mat[0].size() , vector<int>(k+1,-1)));;
        return help(mat , mat[0][0] , k , 0 , 0, dp);
    }

/*
                ********************* using memoization and iteration ***********************
*/

int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        
        if(mat[0][0]<=k) dp[0][0][mat[0][0]] = 1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int sum ;
                for(int a = 0 ; a <= k ; a++){
                    sum = a ;
                    if(sum - mat[i][j] >= 0 ){
                        if(i > 0){
                            dp[i][j][sum] += dp[i-1][j][sum-mat[i][j]];
                        }
                        if(j > 0){
                            dp[i][j][sum] += dp[i][j-1][sum-mat[i][j]];
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1][k];
    }
