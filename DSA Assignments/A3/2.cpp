#include<bits/stdc++.h>

using namespace std ;

long long minCostPath(int n , int m , vector<vector<int>> &grid){ // for going from left to bottom a is m-1 and b is n-1 and for right to up it's a is 0 , b is 0
    queue<pair<pair<int,int> ,long long>>q ; // contains corrds and curr cost
    vector<vector<long long>> min_cost(n , vector<long long>(m , INT_MAX));
    // vector<vector<bool>> vis(n , vector<bool>(m ,false));

    for(int i = 0 ; i<n ; i++){
        q.push({{i,0},grid[i][0]});
        min_cost[i][0] = grid[i][0];
        //vis[i][0] = true ;
    }
    for(int i = 0 ; i<m ; i++){
        q.push({{n-1,i},grid[n-1][i]});
        min_cost[n-1][i] = grid[n-1][i];
        //vis[n-1][i] = true ;
    }
    long long ans = INT_MAX ;
    while(!q.empty()){
        int row = q.front().first.first , col = q.front().first.second ;
        long long cost=q.front().second ;
        q.pop();
        if((row == 0 || col == m-1)) ans = min(ans , cost);
        else{
            int r[8] = {-1,-1,-1,0,1,1,1,0} , c[8] = {-1,0,1,1,1,0,-1,-1};
            for(int i = 0 ; i < 8 ; i++){
                int nRow = row+r[i] , nCol = col+c[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&( min_cost[nRow][nCol] > cost+(long long)grid[nRow][nCol])){
                    min_cost[nRow][nCol] = cost+(long long)grid[nRow][nCol];
                    q.push({{nRow,nCol},cost+grid[nRow][nCol]});
                }
            }
        }
    }

    return ans;
}

int main(){
    int t = 1;
    cin>>t ;
    while(t--){
        int n , m ;
        cin>>n>>m ;

        vector<vector<int>> grid(n , vector<int>(m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++) cin>>grid[i][j];
        }
        cout<<min(minCostPath(n , m , grid) , min((long long)grid[0][0],(long long)grid[n-1][m-1]))<<endl;
    }

    return 0 ;
}