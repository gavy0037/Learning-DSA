/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
*/

#include<bits/stdc++.h>

using namespace std ;

int timer = 0 ;

void dfs(vector<vector<int>> &adjList , int node , int parent , vector<int> &vis , vector<int> &insertionTime , vector<int> &lowestInTime,  vector<vector<int>> &bridges){
    vis[node] = 1 ;
    insertionTime[node] = lowestInTime[node] = timer++;

    for(auto it : adjList[node]){
        if(it == parent) continue ;

        else if(!vis[it]){
            dfs(adjList  , it , node , vis , insertionTime , lowestInTime,bridges);
            lowestInTime[node] = min(lowestInTime[node] , lowestInTime[it]);

            if(lowestInTime[it] > insertionTime[node]){
                bridges.push_back({it,node});
            }
        }else{
            lowestInTime[node] = min(lowestInTime[it] , lowestInTime[node]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    int V = n ;
    vector<vector<int>> adjList(V);
    for(auto it : connections){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }
    vector<int> insertionTime(V) , lowestInTime(V) , vis(V);

    vector<vector<int>> bridges ;
    dfs(adjList , 0 , -1 , vis , insertionTime ,lowestInTime , bridges);
    return bridges ;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
}