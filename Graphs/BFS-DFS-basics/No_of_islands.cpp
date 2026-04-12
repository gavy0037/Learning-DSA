/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally, vertically or diagonally . You may assume all neigbouring cells of the grid are all surrounded by water.
*/

#include<iostream>
#include<vector>
using namespace std ;


bool isvalid(int row , int col , int n , int m){
    return row >=0 && col >= 0 && row < n && col < m  ;
}

void dfs(vector<vector<char>> &mat , vector<vector<bool>> &vis , int row , int col){
    int n = mat.size() , m = mat[0].size();
    int r[] = {-1,-1,0,1,1,1,0,-1};
    int c[] = {0,1,1,1,0,-1,-1,-1};
    for(int i = 0 ;i < 8 ; i++){
        if(isvalid(row+r[i] , col+c[i] , n, m) && mat[row+r[i]][col+c[i]] == '1'){
            if(!vis[row+r[i]][col+c[i]]){
                vis[row+r[i]][col+c[i]] = true ;
                dfs(mat , vis , row+r[i] , col+c[i]);
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size() , m = grid[0].size() , islands = 0 ;
    vector<vector<bool>> vis(n , vector<bool>(m , false)) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                vis[i][j] = true ;
                dfs(grid , vis , i , j);
                islands++;
            }
        }
    }
    return islands ;
}