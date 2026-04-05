/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/

#include<bits/stdc++.h>

using namespace std ;

vector<vector<int>> getAdjList(int v , vector<vector<int>> &edges){
    vector<vector<int>> adjList(v);
    for(auto v : edges){
        adjList[v[1]].push_back(v[0]);
    }
    
    return adjList ;
}
bool dfs_topoSort_and_cycleDetect(vector<vector<int>> &adjList , int node ,vector<bool> &vis ,vector<bool> &path, stack<int> &st){
    vis[node] = true ;
    path[node] = true ;
    for(auto v : adjList[node]){
        if(!vis[v]){
            if(!dfs_topoSort_and_cycleDetect(adjList , v , vis , path , st)) return false ;
        }else if(path[v]) return false ;
    }
    path[node] = false ;
    st.push(node);

    return true ;
}
bool CourseSchedule_1(int numCourses, vector<vector<int>>& prerequisites) {
    int v = numCourses ;
    vector<vector<int>> adjList = getAdjList(v , prerequisites);
    vector<bool> vis(v,false) , path(v , false);
    stack<int> st ;
    for(int i = 0 ; i < v ; i++){
        if(!vis[i] && !dfs_topoSort_and_cycleDetect(adjList , i , vis,path , st)) return false;
    }
    return st.size() == v ;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}