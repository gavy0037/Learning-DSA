/*

    LEETCODE 802

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

#include<bits/stdc++.h>

using namespace std ;


bool isSafe(const vector<vector<int>>& adjList, int node, vector<int>& vis, vector<int>& path, vector<int>& ans) {
    // 1. Node intrinsically manages its own path marking! 
    vis[node] = 1;
    path[node] = 1;

    for (int neighbor : adjList[node]) {
        if (!vis[neighbor]) {
            // If the neighbor turns out to be unsafe, I am unsafe
            if (!isSafe(adjList, neighbor, vis, path, ans)) {
                return false;
            }
        } 
        // 2. Cycle found OR neighbor was previously marked unsafe
        else if (path[neighbor] || !ans[neighbor]) {
            return false; 
        }
    }

    // 3. Backtrack from active path and mark permanently safe
    path[node] = 0;
    ans[node] = 1;
    return true;
}


vector<int> eventualSafeNodes(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> vis(n, 0), path(n, 0), ans(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            isSafe(adjList, i, vis, path, ans);
        }
    }
    
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (ans[i]) res.push_back(i);
    }
    
    return res;
}