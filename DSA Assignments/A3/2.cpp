#include<bits/stdc++.h>

using namespace std ;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n , m ;
        cin>>n>>m;
        vector<vector<int>>grid(n , vector<int>(m));

        for(int i=0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++) cin>>grid[i][j];
        }

        // find the shortest path from left or bottom to right or top

        vector<vector<long>> min_cost(n , vector<long>(m,1e9));
        set<pair<long , pair<int , int>>>st ;
        for(int i = 0 ; i < n ;i++){
            st.insert({grid[i][0] , {i,0}});
            min_cost[i][0] = grid[i][0];
        }

        for(int i = 0 ; i < m ;i++){
            st.insert({grid[n-1][i],{n-1,i}});
            min_cost[n-1][i] = grid[n-1][i];
        }
        int r[8] = {-1,-1,-1,0,1,1,1,0} , c[8] = {-1,0,1,1,1,0,-1,-1};
        while(!st.empty()){
            auto curr = *(st.begin());
            st.erase(curr);

            long cost = curr.first ;
            int row = curr.second.first , col = curr.second.second ;

            for(int i= 0 ; i < 8 ; i++){
                int nRow = row+r[i] ,nCol = col+c[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    if(min_cost[nRow][nCol] > cost+(long)grid[nRow][nCol]){
                        if(st.count({min_cost[nRow][nCol] ,{nRow,nCol}})){
                            st.erase({min_cost[nRow][nCol] ,{nRow,nCol}});
                        }

                        min_cost[nRow][nCol] = cost+(long)grid[nRow][nCol];
                        st.insert({min_cost[nRow][nCol] ,{nRow,nCol}});
                    }
                }
            }
        }
        long ans = INT_MAX ;
        for(int i = 0 ; i < n ;i++){
            ans = min(min_cost[i][m-1],ans);
        }

        for(int i = 0 ; i < m ;i++){
            ans = min(min_cost[0][i],ans);
        }

        cout<<ans<<endl;
    }
}