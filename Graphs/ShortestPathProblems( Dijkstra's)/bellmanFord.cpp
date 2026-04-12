#include<bits/stdc++.h>

using namespace std ;

vector<int> bellmanFord(int V , vector<vector<int>> &edges , int src){
    vector<int> distance(V , 1e9);
    distance[src] = 0;
    
    for(int i = 0 ; i < V-1 ; i++){
        for(auto it : edges){
            int u = it[0] , v = it[1] , w = it[2];

            if(distance[u] != 1e9 && distance[v] > distance[u]+w){
                distance[v] = distance[u]+w ;
            }
        }
    }

    // see in one more iteration that if the distance of a node can be further reduced , then there is a negetive cycle
    for(auto it : edges){
        int u = it[0] , v = it[1] , w = it[2];
        if(distance[u] != 1e9 && distance[v] > distance[u]+w){
            return {-1};
        }
    }

    return distance;
}