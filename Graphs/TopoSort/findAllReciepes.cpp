#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Make a graph , from the redipes to ingredients.Using a map , store what all is reachable or makeable , do kahn's algo and get the answer

        unordered_map<string , int>mp ;
        unordered_map<int, string> ogMapping ;
        int val = 0;
        for(auto s : recipes){
            mp[s]= val ;
            ogMapping[val] = s ;
            val++;
        }
        int cap = val ;
        for(auto v : ingredients){
            for(auto s : v){
                if(mp.find(s) == mp.end()){
                    mp[s]= val ;
                    ogMapping[val] = s ;
                    val++;
                }
            }
        }
        int n = val;
        vector<vector<int>> adjList(n);

        vector<int>indeg(n,0);
        for(int i = 0 ; i < recipes.size() ; i++){
            for(int j = 0 ; j < ingredients[i].size() ; j++){
                int u = mp[recipes[i]] , v = mp[ingredients[i][j]];
                adjList[v].push_back(u);
                indeg[u]++;
            }
        }
        queue<int>q;
        for(auto s : supplies){
            if(mp.find(s) != mp.end()) q.push(mp[s]);
        }
        vector<string>ans ;
        // now just topo sort them
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr < cap) ans.push_back(ogMapping[curr]);

            for(auto i : adjList[curr]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }

        return ans ;

    }
};