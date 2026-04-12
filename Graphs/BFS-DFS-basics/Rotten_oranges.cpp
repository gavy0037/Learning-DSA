/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q ;
    int two_count = 0 ;
    for(int i = 0 ;i < grid.size(); i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            if(grid[i][j] == 2){
                q.push({i , j});
                two_count++ ;
            }
        }
    }

    if(!two_count) return -1 ; // if there are no rotten orages.
    vector<int> r = {-1,0,1,0} , c = {0,1,0,-1};
    int time = 0 ;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            int row = q.front().first , col = q.front().second;
            q.pop();
            for(int i = 0 ; i< 4 ;i++){
                int new_row = row+r[i] , new_col = col+c[i];
                if( new_row >= 0 && new_col >=0 && new_row < grid.size() && new_col < grid[0].size() && grid[new_row][new_col] == 1){
                    grid[new_row][new_col] = 2 ;
                    q.push({new_row , new_col});
                }
            }
        }
        time++;
    }
    for(auto v : grid){
        for(int i : v){
            if( i == 1) return -1 ;
        }
    }
    return time-1 ;// as the last elements in queue will see and won't find any unrotten orages but at that time the queue will still have some elements i.e. the last batch of orages.
}