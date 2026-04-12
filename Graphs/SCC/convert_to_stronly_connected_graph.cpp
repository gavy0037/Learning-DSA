/*
Given a graph , you can insert edges , make the whole graph stronlgy connected using minimum number of edges.
*/

#include<bits/stdc++.h>

using namespace std ;


void dfs1(vector<vector<int>> &adjList , int node , vector<int> &vis , stack<int> &st){
    vis[node] = 1;
    for(auto it : adjList[node]){
        if(!vis[it]) dfs1(adjList ,it , vis , st);
    }
    st.push(node);
}

void dfs2(vector<vector<int>> &adjList , int node , vector<int> &vis , int id , vector<int> &ids){
    vis[node] = 1;
    for(auto it : adjList[node]){
        if(!vis[it]) dfs2(adjList ,it , vis , id , ids);
    }
    ids[node] = id ;
}


int main(){
    int n , m ;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1) , adjListR(n+1);
    while(m--){
        int u , v ;
        cin>>u>>v ;

        adjList[u].push_back(v);
        adjListR[v].push_back(u);
    }

    // now using kosaRaju , convert to condensed graph

    vector<int>vis(n+1 , 0);
    stack<int> st ;
    for(int i = 1 ; i<=n ; i++){
        if(!vis[i]) dfs1(adjList , i , vis , st);
    }

    vis = vector<int>(n+1,0);
    vector<int>ids(n+1,0);
    int id = 0 ;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            dfs2(adjListR , node , vis , id , ids);
            id++;
        }
    }

    vector<vector<int>> adjCondensed(id);
    vector<int> outDegCondensed(id , 0) , indegCondensed(id,0);
    for(int i = 1 ;i <= n; i++){
        for(auto j : adjList[i]){
            if(ids[i] != ids[j]){
                adjCondensed[ids[i]].push_back(ids[j]);
                outDegCondensed[ids[i]]++;
                indegCondensed[ids[j]]++;
            }
        }
    }
    int in = 0 , out = 0 ;
    for(int i = 0 ;i < id ; i++){
        if(indegCondensed[i] == 0) in++;
        if(outDegCondensed[i] == 0) out++;
    }
    // for the condensed graph , now calculate the nodes with indegree 0 and outdegree 0
    // the min number of edges would be the max of the number of nodes with indeg 0 and outdeg0

    if(id == 1) cout<<0<<endl;
    else cout<<max(in , out)<<endl;

    return 0 ;
}