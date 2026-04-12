/*
    FIND SHORTEST PATH OF EACH NODE FROM A GIVEN SOURCE NODE
*/


#include<bits/stdc++.h>

using namespace std ;



void dfs(int V , vector<vector<pair<int, int>>> &adjList , vector<int> &vis , stack<int> &st , int node){
    vis[node] = 1 ;
    for(auto it : adjList[node]){
        if(!vis[it.first]) dfs(V , adjList , vis , st , it.first);
    }
    
    st.push(node);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // code here
    vector<vector<pair<int, int>>> adjList(V); // {node , weight}
    for(auto it : edges){
        adjList[it[0]].push_back({it[1] , it[2]});
    }
    
    vector<int> vis(V,0);
    stack<int>st ;
    for(int i = 0 ; i < V ; i++){
        if(!vis[i]) dfs(V , adjList , vis , st , i);
    }
    
    vector<int> min_dis(V,1e9);
    min_dis[0] = 0; // source node is 0 , so it's distance from 0 is 0 only
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto i : adjList[node]){
            min_dis[i.first] = min(min_dis[i.first] , i.second+min_dis[node]);
        }
    }
    for(int i = 0 ; i < V ; i++){
        if(min_dis[i] == 1e9) min_dis[i] = -1 ;
    }
    return min_dis ;
}