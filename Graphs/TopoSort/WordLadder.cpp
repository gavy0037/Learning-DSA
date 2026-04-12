/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

*/


#include<bits/stdc++.h>

using namespace std;
unordered_map<string , int> mpp ;
string b ;
vector<vector<string>> ans;
void dfs(string word , vector<string> &seq){
    if(word == b){
        reverse(seq.begin() , seq.end());
        ans.push_back(seq);
        reverse(seq.begin() , seq.end());
        return ;
    }
    int originalWordStep = mpp[word];
    for(int i = 0 ; i < word.size() ; i++){
        char og = word[i];
        for(char c = 'a' ; c <= 'z' ; c++){
            word[i] = c; 

            if(mpp.find(word) != mpp.end() 
                && mpp[word] + 1 == originalWordStep){
                    seq.push_back(word);
                    dfs(word , seq);
                    seq.pop_back();
            }
        }
        word[i] = og ;            
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<string>q ;
    b = beginWord;
    unordered_set<string> st(wordList.begin() , wordList.end());
    int step = 1;
    q.push({beginWord});
    mpp[beginWord] = 1;
    st.erase(beginWord);
    while(!q.empty()){
        string word = q.front();
        q.pop();
        if(word == endWord) break ;
        int step = mpp[word];
        for(int i = 0 ; i < word.size() ; i++){
            char og = word[i];
            for(char c = 'a' ; c <= 'z' ; c++){
                word[i] = c; 

                if(st.count(word)){
                    q.push(word);
                    mpp[word] = step+1;
                    st.erase(word);
                }
            }
            word[i] = og ;            
        }
    }
    if(mpp.find(endWord) != mpp.end()){
        vector<string>seq ;
        seq.push_back(endWord);
        dfs(endWord , seq);
    }
    return ans;
}