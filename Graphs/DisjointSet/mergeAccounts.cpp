/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        unordered_map<string , int> mp;
        DisjointSet ds(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    ds.unionByRank(mp[accounts[i][j]] , i);
                }else{
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> temp(n);
        for(auto pair : mp){
            auto key = pair.first ;
            int idx = ds.findUltimateParent(mp[key]);
            temp[idx].push_back(key);
        }
        vector<vector<string>>ans;
        int size = 0 ;
        for(int i=0 ;i < n ; i++){
            if(temp[i].size() == 0) continue ;
            size++;
            ans.push_back({accounts[i][0]}); // push the name in the end vector of ans
            for(auto &email : temp[i]) ans[size-1].push_back(email);
        }

        for(auto &v : ans) sort(v.begin()+1 , v.end());
        return ans ;
    }
};