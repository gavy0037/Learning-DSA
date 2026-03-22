#include<bits/stdc++.h>

using namespace std ;


bool check_bipartite(int v, vector<vector<int>>& adjList){ // This function is for checking bipartite in a connected componenent so some other function must use this function as helper and iterate over all the vertices and also maintain a color vector of it's own
    vector<int> color(v , -1);
    queue<int> q; 
    
    q.push(0);
    color[0] = 0 ;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : adjList[curr]){
            if(color[i] == -1){
                color[i] = 1-color[curr] ;
                q.push(i);
            }else{
                if(color[curr] == color[i]) return false ;
            }
        }
    }

    return true ;
}

bool check_bipartite_DFS(int v , vector<vector<int>> &adjList , vector<int> &color ,int node ,int c){
    color[node] = c ;
    bool ans = true ;
    for(auto i : adjList[node]){
        if(color[i] == -1){
            ans&=check_bipartite_DFS(v , adjList , color , i ,1-c);
        }else if(color[node] == color[i]){
            return false ;
        }
    }
    return ans ;
}