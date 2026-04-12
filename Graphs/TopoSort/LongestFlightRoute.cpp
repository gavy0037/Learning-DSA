/*
    CSES Longest Flight Route

Given a DAG find the longest path between node 1 to node n 
print length of the path and the path itself.
*/

#include<bits/stdc++.h>

using namespace std ;

void dfs(vector<vector<int>> &adjList, vector<int> &vis , int node , stack<int> &st){
    vis[node] = 1 ;
    for(auto i : adjList[node]){
        if(!vis[i]) dfs(adjList , vis , i , st);
    }
    st.push(node);
}
void maximumDistance(vector<vector<int>> &edges, int v, int src) {
    // code here
    vector<vector<int>> adjList(v);
    for(auto it : edges){
        adjList[it[0]-1].push_back(it[1]-1);
    }
    vector<int>vis(v,0);
    stack<int>st ;
    for(int i = 0 ; i < v ; i++){
        if(!vis[i]) dfs(adjList , vis , i , st);
    }
    vector<int>max_dis(v,INT_MIN);
    max_dis[src] = 0;
    vector<int>parent(v,-1);
    parent[src] = -1 ;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        
        for(auto i : adjList[curr]){
            if(max_dis[curr] >= 0){
                if(max_dis[curr]+1 > max_dis[i]){
                    max_dis[i] = max_dis[curr]+1;
                    parent[i] = curr ;
                }
            }
            // This is if is because i am assuming that if node's parent's path has been done then i am calulating node's path based on it's parent , but if dis of parent is -INF then it has not been reached yet hence i should not compute node's distance
        }
    }
    if(max_dis[v-1] == INT_MIN){
        cout<<"IMPOSSIBLE\n";
        return ;
    }
    cout<<max_dis[v-1]+1<<endl ;
    vector<int>path;
    int node = v-1 ;
    while(node != 0){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(0);
    reverse(path.begin() , path.end());
    for(int i = 0 ; i < path.size() ; i++){
        cout<<path[i]+1<<" ";
    }
    cout<<endl ;
    return; 
}

int main(){
    int n , m ;
    cin>>n>>m ;
    vector<vector<int>>edges;
    while(m--){
        int a , b ;
        cin>>a>>b ;
        edges.push_back({a,b});
    }
    maximumDistance(edges , n , 0);

    return 0 ;
}