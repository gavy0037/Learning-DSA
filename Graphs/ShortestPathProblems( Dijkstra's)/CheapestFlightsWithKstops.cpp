/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/


#include<bits/stdc++.h>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // need to find the shortest path with length <= k
    vector<vector<pair<int, int> >> adjList(n);
    for(auto it : flights){
        adjList[it[0]].push_back({it[1] , it[2]});
    }

    // make a set of type - price , stops , node -- in length will be number of nodes visited excluding src and dst
    set<vector<int>>st ;
    st.insert({0,0,src});
    // our minDist will store node -> price , length
    vector<pair<int,int>> minCost(n , {1e9,1e9});
    minCost[src] = {0,0};
    while(!st.empty()){
        auto curr = *(st.begin());
        int currentPrice = curr[0] , currentStops = curr[1] , node = curr[2];
        st.erase(curr);
        if(node == dst && currentStops-1 <= k){
            cout<<currentStops << " " << k <<endl;
            return currentPrice;
        }
        for(auto it : adjList[node]){
            if(minCost[it.first].first > currentPrice + it.second || minCost[it.first].second > currentStops+1){
                // trick here is that we should not delete other paths for this it node , as if we do and find a cheaper path , it might cost less but has more stops where as if the path we deleted had higher price but less stops , then we should have retained it
                minCost[it.first].first = currentPrice+it.second;
                minCost[it.first].second = currentStops+1;
                st.insert({minCost[it.first].first , minCost[it.first].second , it.first});
            }   
        }
    }

    return -1 ;
}