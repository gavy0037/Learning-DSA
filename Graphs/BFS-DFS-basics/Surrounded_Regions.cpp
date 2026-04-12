/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/

#include<iostream>
#include<vector>

using namespace std ;

bool isvalid(int n , int m , int r , int c){
    return r >= 0 && c >= 0 && r < n && c < m ;
}

void dfs(vector<vector<char>> &grid ,vector<vector<int>> &vis , int r[] , int c[] , int row , int col){// Mark all the O's that are connected to row , col as visited
    vis[row][col] = 1 ;
    for(int i = 0 ; i < 4 ; i++){
        int new_row = row+r[i] , new_col = col+c[i];
        if(isvalid(grid.size() , grid[0].size() , new_row , new_col) && grid[new_row][new_col] == 'O' && !vis[new_row][new_col]){
            dfs(grid , vis , r , c , new_row , new_col);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size() , m = board[0].size();
    vector<vector<int>> vis(n , vector<int>(m , 0));
    int r[] = {-1,0,1,0} , c[] = {0,1,0,-1};
    // now go through boundry and if it is O then dfs it
    for(int i = 0 ; i < n ; i++){ // doing the coloumn boundry of both sides
        if(board[i][0] == 'O' && !vis[i][0]) dfs(board , vis , r ,c , i , 0 );
        if(board[i][m-1] == 'O' && !vis[i][m-1]) dfs(board , vis , r ,c , i , m-1 );
    }
    for(int i = 0 ; i < m ; i++){
        if(board[0][i] == 'O' && !vis[0][i]) dfs(board , vis , r , c , 0 , i);
        if(board[n-1][i] == 'O' && !vis[n-1][i]) dfs(board , vis , r , c , n-1 , i);
    }

    for(int i = 0 ; i< n; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
        }
    }
}