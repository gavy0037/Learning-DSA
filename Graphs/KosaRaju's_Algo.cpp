#include<bits/stdc++.h>

using namespace std ;

void dfs(vector<vector<int>> &adjList , int node , vector<int> &vis , stack<int> &st){
    vis[node] = 1 ;
    for(auto v : adjList[node]){
        if(!vis[v]) dfs(adjList , v , vis , st);
    }

    st.push(node);
}

void dfs2(vector<vector<int>> &adjList , int node , vector<int> &vis, vector<int> &curr){
    vis[node] = 1 ;
    curr.push_back(node);
    for(auto v : adjList[node]){
        if(!vis[v]) dfs2(adjList , v , vis , curr);
    }
}

vector<vector<int>> kosaRaju(int V , vector<vector<int>> &adjList){
    // first store the vertices according to finishing time

    vector<int> vis(V ,0);
    stack<int> st ;
    for(int i = 0 ; i < V ; i++){
        if(!vis[i]) dfs(adjList , i , vis,st);
    }
    // now reverse the graph

    vector<vector<int>> adjListR(V);
    for(int i = 0 ; i < V ; i++){
        for(auto v : adjList[i]){
            adjListR[v].push_back(i);
        }
    }
    // now with the order of things from the stack do dfs and store them in something
    int count = 0 ;
    vector<vector<int>> ans ;

    vis = vector<int>(V,0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            vector<int> temp ;
            dfs2(adjListR , node, vis ,temp);
            ans.push_back(temp);
            count++;
        }
    }

    return ans ;
}

int main(){


}