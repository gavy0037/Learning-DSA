/*
Given n, m denoting the row and column of the 2D matrix, and an array A of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix.

The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation.

The directions to check for the island are up, down, right, left. The answer array will be of size k.
*/

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

int findNode(int r , int c , int n , int m){
    return r*m+c;
}

vector<int> numOfIslands__2(int n, int m, vector<vector<int>> &A){
    int t = n*m;

    DisjointSet ds(t);
    vector<vector<int>> mat(n, vector<int>(m , 0));
    int r[4] = {-1,0,1,0} , c[4] = {0,1,0,-1};

    int count = 0 ;
    vector<int>ans ;
    for(auto it : A){
        int row = it[0] , col = it[1];
        int curr_node =  findNode(row,col,  n , m);

        if(mat[row][col]){
            // this cell has been already marked
            ans.push_back(count);
            continue ;
        }

        mat[row][col] = 1 ;
        count++; // this is for if this was not connected to any component , now we will investigate and decrease it if found connected
        for(int i = 0 ; i < 4 ; i++){
            int nRow = row + r[i] , nCol = col+c[i];
            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && mat[nRow][nCol]){
                int parent_node = findNode(nRow , nCol , n , m);
                // if already connected cells then do not reduce the counter
                if(ds.findUltimateParent(curr_node) != ds.findUltimateParent(parent_node)) count--;
                ds.unionByRank(curr_node , parent_node);
            }
        }
        ans.push_back(count);
    }

    return ans;
}