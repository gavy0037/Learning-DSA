#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

    private:
    public:
        vector<int>rank, parent, size ;
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // treat each row number and col number as a node

        int maxRow = 0 , maxCol = 0 ;
        // need to find the integers that are acutally in dsu and then iterate over them
        unordered_set<int>st ;
        for(auto it : stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }

        DisjointSet ds(maxRow+maxCol+1);

        for(auto it : stones){
            int nodeRow = it[0] , nodeCol = it[1];

            ds.unionBySize(nodeRow , nodeCol+maxRow+1);
            st.insert(it[0]);
            st.insert(it[1]+maxRow+1);
        }

        // now find the number of connected components , there is a twist in this this question , we can't add directly the size of each component , i coundn't understand why ?

        int count = 0 ;
        for(int i : st){
            if(ds.findUltimateParent(i) == i){
                count++;
            }
        }

        return stones.size()-count ;
    }
};