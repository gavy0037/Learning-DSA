#include<bits/stdc++.h>

using namespace std ;


vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<vector<pair<int , int>>> adjList(n+1);
    
    for(auto it : edges){
        adjList[it[0]].push_back({it[1],it[2]});
        adjList[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<int , int> , vector<pair<int ,int>> , greater<pair<int ,int>> > min_heap ;
    vector<int> parent(n+1) , min_dis(n+1,1e9);
    
    min_dis[1] = 0;
    min_heap.push({0,1});
    while(!min_heap.empty()){
        int dis = min_heap.top().first ,node =  min_heap.top().second ;
        min_heap.pop();
        if(node == n) break ;
        for(auto it : adjList[node]){
            if(min_dis[it.first] > it.second+min_dis[node]){
                min_dis[it.first] = it.second+min_dis[node];
                parent[it.first] = node ;
                
                min_heap.push({min_dis[it.first] , it.first});
            }
        }
    }
    vector<int>ans ;
    if(min_dis[n] == 1e9) return {-1};
    
    
    int node = n; 
    while(node != 1){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    ans.push_back(min_dis[n]);
    
    reverse(ans.begin() , ans.end());
    
    return ans;
}