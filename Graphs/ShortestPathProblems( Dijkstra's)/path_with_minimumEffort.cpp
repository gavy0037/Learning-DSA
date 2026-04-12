/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/


#include<bits/stdc++.h>

using namespace std ;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size() , m = heights[0].size();
    vector<vector<int>> min_effort(n , vector<int>(m , 1e9));

    set<pair<int,pair<int , int>>> st;
    st.insert({0,{0,0}});
    
    min_effort[0][0] = 0 ;
    int r[4] = {-1,0,1,0} , c[4] = {0,1,0,-1};

    while(!st.empty()){
        auto curr = *(st.begin()) ;
        auto coord = curr.second;
        int step = curr.first ;
        st.erase(curr);
        
        int row = coord.first , col = coord.second ;
        if(row == n-1 && col == m-1){
            return step ;
        }
        for(int i = 0 ; i < 4 ;i++){
            int nRow = row+r[i] , nCol = col+c[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                int currentEffort = abs(heights[row][col] - heights[nRow][nCol]);
                int effort_if_take_current_cell = max(currentEffort , min_effort[row][col]);

                if(effort_if_take_current_cell < min_effort[nRow][nCol]){
                    if(min_effort[nRow][nCol] != 1e9){
                        st.erase({min_effort[nRow][nCol],{nRow,nCol}});
                    }
                    min_effort[nRow][nCol] = effort_if_take_current_cell;
                    st.insert({min_effort[nRow][nCol] , {nRow,nCol}});
                }
                
            }
        }
    }
    return 0;
}