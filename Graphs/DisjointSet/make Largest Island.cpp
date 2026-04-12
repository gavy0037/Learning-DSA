#include<bits/stdc++.h>

using namespace std ;

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
    int getNode(int r ,int c ,int n){
        return r*n+c;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = n*n;
        DisjointSet ds(t);

        int dr[4] = {-1,0,1,0} , dc[4] = {0,1,0,-1};

        
        for(int i= 0 ; i < n ; i++){
            for(int j= 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    for(int k =0 ; k < 4 ;k++){
                        int nRow = i+dr[k] , nCol= j+dc[k];
                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol]){
                            int currNode = getNode(i,j,n);
                            int otherNode = getNode(nRow , nCol , n);

                            ds.unionBySize(currNode , otherNode);
                        }
                    }
                }
            }
        }
        int size = -1 ;
        for(int i=0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    size = max(size , ds.size[ds.findUltimateParent(getNode(i,j,n))]);
                    continue ;
                }
                int maxSize = 1;
                unordered_set<int>visitedParent;
                for(int k = 0 ; k < 4 ; k++){
                    int nRow = i+dr[k] , nCol = j + dc[k];
                    int newNode = getNode(nRow , nCol , n);
                    if(nRow >= 0 && nRow < n && nCol >=0 && nCol < n && grid[nRow][nCol]
                        && visitedParent.find(ds.findUltimateParent(newNode)) == visitedParent.end()){
                            int ulp = ds.findUltimateParent(newNode);
                            maxSize+=ds.size[ulp];
                            visitedParent.insert(ulp);
                        }
                }

                size = max(size , maxSize);
            }
        }

        return size ;
    }
};