/*

You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

*/

#include<bits/stdc++.h>

using namespace std ;

char dir(pair<int, int> &a, pair<int, int> &b) {
    // Calculates direction of movement from 'a' to 'b' (a -> b)
    int stRow = a.first, stCol = a.second; 
    int endRow = b.first, endCol = b.second;

    // Row changes (Up / Down)
    if (endRow < stRow) return 'D'; // Row decreased -> moved Up
    if (endRow > stRow) return 'U'; // Row increased -> moved Down
    
    // Column changes (Left / Right)
    if (endCol < stCol) return 'R'; // Col decreased -> moved Left
    if (endCol > stCol) return 'L'; // Col increased -> moved Right

    return 'X'; // Fallback just in case a == b
}

int main(){

    int n , m ;
    cin>>n>>m ;
    pair<int,int> st , end ;
    vector<string>grid(n);
    vector<vector<bool>> vis(n , vector<bool> (m , false));
    for(int i = 0; i < n; i++){
        cin>>grid[i];
        for(int j = 0; j < m ; j++){
            if(grid[i][j] == 'A'){
                st = {i,j};
            }else if(grid[i][j] == 'B'){
                end = {i,j};
            }
        }
    }
    queue<pair<int , int>> q ;
    vector<vector<pair<int,  int>>> parent(n , vector<pair<int , int>>(m , {-1,-1})) ;
    q.push(st);
    vis[st.first][st.second] = true ;
    parent[st.first][st.second] = {-1,-1};

    int dr[4] = {-1,0,1,0} , dc[4] = {0,1,0,-1};
    bool found = false ;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr == end){
            found = true ;
            break ;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nRow = curr.first+dr[i] , nCol = curr.second + dc[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && !(grid[nRow][nCol] == '#')){
                q.push({nRow,nCol});
                vis[nRow][nCol] = true ;
                parent[nRow][nCol] = curr ;
            }
        }
        
    }

    if(found){
        cout<<"YES\n";
        string path ="";
        pair<int ,int> temp = end ;
        while(temp != st){
            path+=dir(temp, parent[temp.first][temp.second]);

            temp = parent[temp.first][temp.second] ;
        }
        reverse(path.begin(), path.end());
        cout<<path.length()<<endl<<path<<endl;
    }else{
        cout<<"NO\n";
    }
    return 0 ;
}