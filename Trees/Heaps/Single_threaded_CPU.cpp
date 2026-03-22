/*

        LEETCODE - 1834
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std ;

class cmp{
    public:
        bool operator()(vector<int> &a , vector<int> &b){
            if(a[1] != b[1]){
                return a[1] > b[1] ;
            }

            return a[2]> b[2] ;
        }
};

class Solution {
public:

    vector<int> getOrder(vector<vector<int>>& tasks) {
        // make a priority queue(like a max heap basically that element on top that has highest priority)
        priority_queue<vector<int>, vector<vector<int>> , cmp>heap ;
        // stored as task[0],task[1] ,index
        int i = 0;
        for(auto &v : tasks){
            v.push_back(i++);
        }

        sort(tasks.begin(),tasks.end());
        vector<int>ans ;
        
        i = 0 ;
        long long time = 0 ;
        while(i < tasks.size()){
            if(!heap.empty()){
                auto curr = heap.top();
                heap.pop();
                time+=curr[1]; // this is the ending time of curr task
                while( i < tasks.size() && tasks[i][0] <= time) heap.push(tasks[i++]);
                ans.push_back(curr[2]);
            }else{
                heap.push(tasks[i]);
                time+=tasks[i][0];
                i++;
            }
        }

        while(!heap.empty()){
            auto curr = heap.top();
            ans.push_back(curr[2]);
            heap.pop();
        }
        return ans ;
    }
};