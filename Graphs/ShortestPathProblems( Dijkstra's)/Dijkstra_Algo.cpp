#include<bits/stdc++.h>

using namespace std ;

vector<int> using_minHeap(int V , vector<vector<pair<int , int> >> &adjList , int src){
    priority_queue<pair<int , int> , vector<pair<int ,int>> , greater<pair<int ,int>> > min_heap ;

    min_heap.push({0,src});
    vector<int>min_dis(V , 1e9);

    min_dis[src] = 0;

    while(!min_heap.empty()){
        int dis = min_heap.top().first , node = min_heap.top().second ;

        min_heap.pop();

        if(dis > min_dis[node]) continue ;// if another neighbour later found a better path for current node , then we are done with this node
        for(auto i : adjList[node]){
            if(min_dis[i.first] > dis+i.second){
                min_dis[i.first] = dis+i.second ;
                min_heap.push({dis+i.second , i.first});
            }
        }
    }

    return min_dis ;
}

vector<int> using_set(int V , vector<vector<pair<int , int> >> &adjList , int src){
    vector<int>min_dis(V, 1e9);
    set<pair<int , int>> st ;
    st.insert({0 , src});

    min_dis[src] =0 ;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second , dis = it.first ;
        st.erase(it);
        for(auto i : adjList[node]){
            int adjNode = i.first ;
            int edgeWeight = i.second ;

            if(dis+edgeWeight < min_dis[adjNode]){
                if(min_dis[adjNode] != 1e9){
                    // it means that this has already been visited and inserted in the set
                    // erase it from set.
                    st.erase({min_dis[adjNode] , adjNode});
                }
                min_dis[adjNode] = dis+edgeWeight ;
                st.insert({min_dis[adjNode] , adjNode});
            }
        }
    }

    return min_dis ;
}

// Given: int V, vector> adj[], int S
// set> st;
// vector dist(V, 1e9);

// st.insert({0, S});
// dist[S] = 0;

// while (!st.empty()) {
// auto it = *(st.begin());
// int node = it.second;
// int dis = it.first;
// st.erase(it);

// for (auto it : adj[node]) {
// int adjNode = it.first;
// int edgeWeight = it.second;

// if (dis + edgeWeight < dist[adjNode]) {
// // Erase if node was already present with a larger distance
// if (dist[adjNode] != 1e9)
// st.erase({dist[adjNode], adjNode});

// dist[adjNode] = dis + edgeWeight;
// st.insert({dist[adjNode], adjNode});
// }
// }
// }
// return dist;