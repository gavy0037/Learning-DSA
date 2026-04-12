/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/

#include<bits/stdc++.h>

using namespace std ;

void dfs(int row , int col , vector<vector<int>> &grid ,vector<vector<int>> &vis, int baseRow , int baseCol, vector<pair<int , int>> &temp){
        vis[row][col] = 1 ;
        temp.push_back({row-baseRow , col-baseCol});
        int r[4] = {-1,0,1,0} , c[4] = {0,1,0,-1};
        for(int i = 0 ;i < 4; i++){
            int nRow = row+r[i] , nCol = col+c[i];
            if(nRow >= 0 && nCol >= 0 && nRow < grid.size() 
            && nCol < grid[0].size() && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                dfs(nRow , nCol , grid , vis , baseRow , baseCol , temp);
            }
        }
        
    }
int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    int n = grid.size() , m = grid[0].size();
    vector<vector<int>> vis(n , vector<int>(m , 0));
    set<vector<pair<int , int>>> st ;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                vector<pair<int , int>> vec ;
                dfs(i , j , grid, vis , i ,j , vec);
                
                st.insert(vec);
            }
        }
    }
    
    return st.size();
}