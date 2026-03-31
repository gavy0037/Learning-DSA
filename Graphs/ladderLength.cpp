#include<bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>st ;
    
    for(auto s : wordList) st.insert(s);

    if(st.find(endWord) == st.end() || beginWord == endWord) return 0 ;

    queue<pair<string , int>> q;
    q.push({beginWord , 1});
    q.pop();
    // distance is chosen as 1 because we need to find the total words in path , if it was edges i would have done distance as 0

    while(!q.empty()){
        string word = q.front().first ;
        int dis = q.front().second ;

        if(word == endWord) return dis ;

        for(int i = 0 ; i < word.length() ; i++){
            char og = word[i];
            for(char k = 'a' ; k <= 'z' ; k++){
                word[i] = k ;

                if(st.find(word) != st.end()){
                    q.push({word, dis+1});
                    st.erase(word); // so that no other word can take this path so that our path remains shortest
                }
            }

            word[i] = og ;// restore the original character
        }
    }

    return 0 ;
}