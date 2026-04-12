#include<bits/stdc++.h>

using namespace std ;

void floydWarshall(vector<vector<int>> &mat) {
    // Code here
    int n= mat.size();
    for(int k= 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if(mat[i][k] != 1e8 && mat[k][j] != 1e8)
                mat[i][j] = min(mat[i][j] , mat[i][k]+mat[k][j]);
            }
        }
    }
}