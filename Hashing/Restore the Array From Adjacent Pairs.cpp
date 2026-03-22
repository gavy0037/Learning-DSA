/*
        LEETCODE 1743
    
    There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

    You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

    It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

    Return the original array nums. If there are multiple solutions, return any of them.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std ;

class Solution {
public:

    // THIS IS JUST LIKE FIRST MAKING A ADJ LIST AND THEN DOING OTHER THINGS LIKE MAKING A VIS ARRAY i.e. USED (set)
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int n = pairs.size()+1;// size of final array
        unordered_map<int , vector<int>>mp ;
        for(auto v : pairs){
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        int st = -1 , end = -1 ;
        for(auto &i : mp){
            if((i.second).size() == 1){
                if(st == -1) st = i.first ;
                else {
                    end = i.first ;
                    break ;
                }
            }
        }

        vector<int>nums(n);
        nums[0] = st ;
        nums[n-1] = end ;
        
        unordered_set<int>used ;
        used.insert(nums[0]);
        for(int i = 1 ; i < n-1 ; i++){
            int first = mp[nums[i-1]][0],second = INT_MIN;
            if(mp[nums[i-1]].size() >1) second = mp[nums[i-1]][1];
            if(used.find(first) == used.end()){
                // use the zeroth element
                nums[i] = first;
                used.insert(first);
            }else if(second != INT_MIN){
                nums[i] = second ;
                used.insert(second);
            }
        }

        return nums ;
    }
};