#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

void dfsHelper(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs) {
    // Mark the current node as visited
    vis[node] = 1;
    dfs.push_back(node);
    
    // Traverse all neighbors
    for (auto it : adj[node]) {
        // If neighbor is not visited, dive deeper into that branch
        if (!vis[it]) {
            dfsHelper(it, adj, vis, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfs;
    
    // Loop through all nodes to handle disconnected components
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsHelper(i, adj, vis, dfs);
        }
    }
    return dfs;
}

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> vis(n, 0); 
    vector<int> bfs; 
    
    // Loop through every possible node
    for (int i = 0; i < n; i++) {
        // If the node hasn't been visited, it's part of a new component
        if (!vis[i]) {
            queue<int> q;
            vis[i] = 1; 
            q.push(i); 

            while(!q.empty()) {
                int node = q.front(); 
                q.pop(); 
                bfs.push_back(node); 

                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1; 
                        q.push(it); 
                    }
                }
            }
        }
    }
    return bfs; 
}
int main(){

}