#include<bits/stdc++.h>

using namespace std ;

bool dfs_topoSort_and_cycleDetect(vector<vector<char>> &adjList , int node ,vector<bool> &vis ,vector<bool> &path,string &s){
    // cout<<node<<endl;
    vis[node] = true ;
    path[node] = true ;
    for(auto v : adjList[node+'a']){
        if(!vis[v-'a']){
            if(!dfs_topoSort_and_cycleDetect(adjList , v-'a' , vis , path , s)) return false ;
        }else if(path[v-'a']) return false ;
    }
    path[node] = false ;
    s.push_back(node+'a');
    return true ;
}

string findOrder(vector<string> &words) {
    // code here
    vector<vector<char>> adjList(26) ;
    vector<vector<bool>> adjMatrix(26 , vector<bool>(26,false));
    unordered_set<char>st ;
    for(int i = 1 ; i < words.size() ; i++){
        if(words[i] != words[i-1]){
            // find the first non matching character and add a edge in graph for them

            int length = min(words[i-1].length() ,words[i].length());

            for(int j = 0 ;j < length ; j++){
                if(words[i-1][j] != words[i][j]){
                    st.insert(words[i-1][j]);
                    st.insert(words[i][j]);
                    if(adjMatrix[words[i][j] - 'a'][words[i-1][j] - 'a']){
                        cout<<i<<" "<<j<<endl ;
                        return "";
                    }
                    else{
                        if(!adjMatrix[words[i-1][j] - 'a'][words[i][j] - 'a'])
                        adjList[words[i-1][j]].push_back(words[i][j]);
                        adjMatrix[words[i-1][j] - 'a'][words[i][j] - 'a'] = true ;
                    }
                    break ;
                }
            }
        }
    }
    vector<bool> vis(26,false) , path(26 , false);
    string s ;
    for(int i = 0 ; i < 26 ; i++){
        if(!vis[i] && st.find(i+'a') != st.end() && !dfs_topoSort_and_cycleDetect(adjList , i , vis,path , s)) return "";
    }
    reverse(s.begin() , s.end());

    return s ;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    n = 5 ;
    vector<string> dict ;
    // for(int i =0 ;i < n ; i++){
    //     string s ;
    //     cin>>s ;
    //     dict.push_back(s);
    // }
    dict = {"baa" , "abcd" , "abca" , "cab" , "cad"};
    string ans = findOrder(dict);

    cout<<ans<<endl ;

    return 0 ;
}