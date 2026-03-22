/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

bool DetectCycle_BFS(int v , vector<vector<int>>& E){
    // vertices are zero indexed
    // we have atleast one vertex
    // first make a adjList
    vector<int> adjList[v];
    for(auto i : E){
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }

    vector<bool>vis(v , false);
    for(int i = 0 ; i < v ; i++){
        if(vis[i]) continue;
        queue<pair<int , int>> q ;// contains element and it's parent
        q.push({i , -1});
        vis[i] = true ;
        while(!q.empty()){
            int curr_element = q.front().first ;
            int parent = q.front().second ;
            q.pop();
            for(int j : adjList[curr_element]){
                if(!vis[j]){
                    vis[j] =true ;
                    q.push({j , curr_element});
                }else if( j != parent){
                    return true ;
                }
            }
        }
    }
    return false;
}

bool dfs(vector<vector<int>> &adjList , vector<bool> &vis ,int curr_node ,int parent){
    for(int i : adjList[curr_node]){
        if(!vis[i]){
            vis[i] = true ;
            if(dfs(adjList , vis , i , curr_node)) return true;
        }else if(i != parent) return true ;
    }
    return false ;
}

bool detectCycle_DFS(int v , vector<vector<int>>& E){
    vector<vector<int>> adjList(v);
    for(auto i : E){
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }

    vector<bool>vis(v , false);
    for(int i = 0 ; i < v ; i++){
        if(vis[i]) continue ;
        vis[i] = true ;
        if(dfs(adjList , vis , i , -1 )) return true ;
    }

    return false ;
}