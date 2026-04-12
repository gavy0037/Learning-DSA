/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
*/

#include<bits/stdc++.h>

using namespace std ;

int timer = 0 ;

void dfs(vector<int> adj[] , int node , int parent , vector<int> &vis , vector<int> &lowestTime , vector<int> &inTime , set<int> &st){
    vis[node] = 1;
    inTime[node] = lowestTime[node] = timer++;
    int child = 0 ;
    for(auto v : adj[node]){
        if(v == parent) continue ;
        else if(!vis[v]){
            dfs(adj , v , node , vis , lowestTime  , inTime,st);
            lowestTime[node] = min(lowestTime[node] , lowestTime[v]);

            if(lowestTime[v] >= inTime[node] && parent != -1){
                st.insert(node);
            }

            child++; // unvisited children
        }else{
            // if it's visited neighour

            lowestTime[node] = min(lowestTime[node] , inTime[v]);
        }
    }
    
    if(child > 1 && parent == -1){
        st.insert(node);
    }
}

vector<int> articulationPoints(int V, vector<int> adj[]) {
    // Code here
    vector<int> mark(V) , vis(V) , lowestTime(V) , inTime(V);
    set<int> st ;
    for(int i = 0 ;i < V ; i++){
        if(!vis[i]) dfs(adj , i , -1 , vis , lowestTime , inTime,st);
    }

    vector<int> ans ;
    for(auto i : st){
        ans.push_back(i);
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


}