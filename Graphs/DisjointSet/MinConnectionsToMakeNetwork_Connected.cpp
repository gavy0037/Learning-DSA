/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/

#include<bits/stdc++.h>

using namespace std ;

class DisjointSet{
    private:
        vector<int>rank, parent, size ;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i = 0 ; i <= n ; i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]) return node ;

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp_u = findUltimateParent(u) , ulp_v = findUltimateParent(v);

            if(ulp_u == ulp_v) return ;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                // attach v to u
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u , int v){
            int ulp_u = findUltimateParent(u) , ulp_v = findUltimateParent(v);

            if(ulp_u == ulp_v) return ;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                // attach v to u
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

class Solution {
public:
    void dfs(vector<vector<int>> &adjList , vector<int> &vis , int node){
        vis[node] = 1;
        for(auto it : adjList[node]){
            if(!vis[it]) dfs(adjList , vis , it);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // find number of reduant edges -1 , if they are greater than the number of connected components , then connected components - 1 is our answer , and if not then -1 i.e. impossible

        // find the number of connected components

        vector<vector<int>> adjList(n);
        for(auto it : connections){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> vis(n , 0);
        int count = 0;
        for(int i=0 ; i < n ; i++){
            if(!vis[i]){
                dfs(adjList , vis , i);
                count++;
            }
        }

        // now count number of redundant edges using disjoint set
        DisjointSet ds(n);
        int redundantEdges = 0 ;
        for(auto it : connections){
            int a = it[0] , b = it[1];
            if(ds.findUltimateParent(a) == ds.findUltimateParent(b)) redundantEdges++;
            else{
                ds.unionByRank(a ,b);
            }
        }
        if(redundantEdges >= count-1) return count-1;

        return -1; 
    }
};