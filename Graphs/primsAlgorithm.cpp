#include<bits/stdc++.h>

using namespace std ;

int kruskalsMST(int V, vector<vector<int>> &edges) {
    // code here
    
    vector<vector<pair<int , int>>>adjList(V);
    for(auto it : edges){
        int u = it[0] , v = it[1] , w = it[2];
        
        adjList[u].push_back({v , w});
        adjList[v].push_back({u , w});
    }
    
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair< int , int>>>pq ;
    
    vector<int>vis(V , 0);
    pq.push({0 , 0});
    
    int sum = 0 ;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int node = curr.second , wt = curr.first ;
        
        if(vis[node] == 1){
            continue ; 
        }
        vis[node] = 1;
        sum+=wt ;
        
        for(auto it : adjList[node]){
            int adjNode = it.first , edgeWeight = it.second ;
            
            if(!vis[adjNode]){
                pq.push({edgeWeight , adjNode});
            }
        }
        
    }
    
    return sum;
}