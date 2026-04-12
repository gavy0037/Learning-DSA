

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std ;

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    // code here
    int n = grid.size() , m = grid[0].size();
    vector<vector<int>> dis(n , vector<int>(m , INT_MAX)) , vis(n , vector<int>(m , 0));
    
    queue<pair<int , int>> q;
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j]){
                dis[i][j] = 0 ;
                vis[i][j] = 1 ;
                q.push({i, j});
            }
        }
    }
    int r[] = {-1, 0 , 1 ,0} , c[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first , col = q.front().second ;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int n_row = row + r[i] , n_col = col + c[i];
            if(n_row >= 0 && n_col>= 0 && n_row < n && n_col < m && grid[n_row][n_col] == 0){
                dis[n_row][n_col] = min(dis[n_row][n_col] , 1+dis[row][col]);
                
                if(!vis[n_row][n_col]){
                    vis[n_row][n_col] = 1 ;
                    q.push({n_row, n_col});
                }
            }
        }
    }

    return dis ;
}