/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.
*/


#include<bits/stdc++.h>

using namespace std ;
int countPaths(int n, vector<vector<int>>& roads) {
    int MOD = 1000000007;
    vector<vector<pair< int , int>>>adjList(n);

    for(auto it : roads){
        adjList[it[0]].push_back({it[1],it[2]});
        adjList[it[1]].push_back({it[0],it[2]});
    }

    priority_queue<pair< long long , int> , vector<pair<long long , int>> , greater<pair< long long , int>> >pq ;

    vector<long long> dist(n, 1e18) , ways(n , 0);

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0}); // dist , node

    while(!pq.empty()){
        long long dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop();

        for(auto it : adjList[node]){
            long long adjNode = it.first , edgeWeight = it.second ;

            if(dis+edgeWeight < dist[adjNode]){
                // this means i have come to this node with this much less weight for the first time

                dist[adjNode] = dis+edgeWeight;

                pq.push({dist[adjNode] , adjNode});
                ways[adjNode] = ways[node];
            }else if(dis+edgeWeight == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node])%MOD;
            }
        }
    }


    return ways[n-1];
}