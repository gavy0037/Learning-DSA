/*
Leetcode 547
No of provinces
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

void dfs(vector<vector<int>> &adjList , vector<bool>vis , int v){
    vis[v] = true ;

    for(int i = 0 ; i < adjList[v].size() ; i++){
        if(adjList[v][i] && !vis[i]) dfs(adjList , vis , v);
    }
}

int connected_components(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<bool>vis(n , false) ;
    int count = 0 ;
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            dfs(adjList , vis , i);
            count++;
        }
    }
    return count ;
}