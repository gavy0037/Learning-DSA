/*
You are given an n x m integer matrix matrix containing non-negative integers.

A non-zero cell (row, col) checks the cells near it as follows:

Let x = matrix[row][col].
Consider every cell within x rows and x columns of (row, col).
Ignore cells that are outside the matrix.
Ignore the cells where both the row distance and column distance are exactly x.
The cell (row, col) is a local maximum if it is non-zero and no considered cell has a value greater than x.

Return an integer denoting the number of local maximums in matrix.


*/

#include<bits/stdc++.h>

using namespace std;

bool local_maximum(int n , int m , int row , int col , vector<vector<vector<int>>> &prefix_sum , vector<vector<int>> &matrix){
    int val = matrix[row][col];
    int r1 = max(0,row-val);
    int c1 = max(0,col-val);
    int r2 = min(n-1 , row+val);
    int c2 = min(m-1 , col+val);
    int count = prefix_sum[val][r2+1][c2+1] - prefix_sum[val][r2+1][c1] - prefix_sum[val][r1][c2+1]
                + prefix_sum[val][r1][c1];

    // Now remove all corners
    int dr[4] = {-val ,-val , val , val};
    int dc[4] = {-val ,val , -val, val};
    for(int k =0 ; k <  4; k++){
        int r =row+dr[k] , c= col+dc[k];

        if(r >= 0 && r < n && c >= 0 && c < m && matrix[r][c] > val) count--;
    }

    return count == 0 ;
}
int countLocalMaximums(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<vector<int>>> pre(201 , vector<vector<int>>(n+1, vector<int>(m+1,0)));
    for(int val = 0 ; val <= 200 ; val++){
        for(int i=0 ; i < n ; i++){
            int rs = 0 ;
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] > val) rs++;
                pre[val][i+1][j+1] = rs+pre[val][i][j+1];
            }
        }
    }
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0 && local_maximum(n, m, i, j, pre, matrix)) count++;
        }
    }
    return count ;
}