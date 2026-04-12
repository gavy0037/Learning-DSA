#include<bits/stdc++.h>

using namespace std ;

void dfs(vector<vector<pair<int,int>>> &adjList, vector<int> &vis , int node , stack<int> &st){
    vis[node] = 1 ;
    for(auto i : adjList[node]){
        if(!vis[i.first]) dfs(adjList , vis , i.first , st);
    }
    st.push(node);
}
vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
    // code here
    vector<vector<pair<int,int>>> adjList(v);
    for(auto it : edges){
        adjList[it[0]].push_back({it[1] , it[2]});
    }
    vector<int>vis(v,0);
    stack<int>st ;
    for(int i = 0 ; i < v ; i++){
        if(!vis[i]) dfs(adjList , vis , i , st);
    }
    vector<int>max_dis(v,INT_MIN);
    max_dis[src] = 0;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        
        for(auto i : adjList[curr]){
            if(max_dis[curr] >= 0) max_dis[i.first] = max(max_dis[i.first] , max_dis[curr]+i.second);
            // This is if is because i am assuming that if node's parent's path has been done then i am calulating node's path based on it's parent , but if dis of parent is -INF then it has not been reached yet hence i should not compute node's distance
        }
    }
    
    return max_dis ;
}