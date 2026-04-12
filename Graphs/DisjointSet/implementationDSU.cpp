#include<bits/stdc++.h>

using namespace std ;

class DisjointSet{

    private:
        vector<int>rank, parent, size ;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i = 0 ; i <= n ; i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]) return node ;

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp_u = findUltimateParent(u) , ulp_v = findUltimateParent(v);

            if(ulp_u == ulp_v) return ;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                // attach v to u
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u , int v){
            int ulp_u = findUltimateParent(u) , ulp_v = findUltimateParent(v);

            if(ulp_u == ulp_v) return ;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                // attach v to u
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};