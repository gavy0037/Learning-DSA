#include<bits/stdc++.h>

using namespace std ;


vector<vector<int>> getAdjList(int v , vector<vector<int>> &edges){
    vector<vector<int>> adjList(v);
    for(auto v : edges){
        adjList[v[0]].push_back(v[1]);
    }
    
    return adjList ;
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<int> indegree(V,0);
    for(auto v : edges){
        indegree[v[1]]++;
    }
    
    // AS THE GRAPH IS DAG , one of it's vertices must have a indegree of 0
    queue<int> q ;
    for(int i = 0 ; i < V ; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> sorted ;
    vector<vector<int>> adjList = getAdjList(V , edges);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for(auto it : adjList[node]){
            indegree[it]--;
            if(!indegree[it]) q.push(it);
        }
    }
    
    return sorted ;
}