#include<bits/stdc++.h>

using namespace std ;


void dfs(vector<vector<int>> &adjList , vector<int> &vis , int node , stack<int> &st){
    vis[node] = 1 ;

    for(auto i: adjList[node]){
        if(!vis[i]){
            dfs(adjList , vis , i , st);
        }
    }

    st.push(node);
}


int main(){
    vector<vector<int>> adjList = {
        {}, // 0
        {}, // 1
        {3}, //2
        {1}, //3
        {0,1}, //4
        {2,0} //5   
    };
    int n ;// number of nodes
    vector<int> topoSort , vis(n,0);
    stack<int> st ;

    dfs(adjList , vis , 0 , st);

    while(!st.empty()){
        topoSort.push_back(st.top());
        st.pop();
    }
}