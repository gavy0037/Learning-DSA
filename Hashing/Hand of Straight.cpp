/*
        LEETCODE 846

    Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

    Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
*/


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std ;


bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize != 0) return false ;

    priority_queue<int , vector<int> , greater<int> > min_heap ;
    map<int , int>mp ;
    for(int i = 0 ; i < hand.size() ; i++){
        if(mp.find(hand[i]) != mp.end()) mp[hand[i]]++;
        else{
            min_heap.push(hand[i]);
            mp[hand[i]] = 1;
        }
    }

    int a=hand.size()/groupSize , b = groupSize ;
    vector<vector<int>>ans(a) ;
    for(int i = 0 ; i < a ; i++){
        while(!min_heap.empty() && mp.find(min_heap.top()) == mp.end()){
            min_heap.pop();
        }
        int st = min_heap.top();
        for(int j = 0 ; j < b ; j++){
            if(mp.find(st+j) == mp.end()){
                return false ;
            }else{
                if(mp[st+j] == 1) mp.erase(st+j);
                else mp[st+j]--;
            }
        }
    }
    return true ;
}