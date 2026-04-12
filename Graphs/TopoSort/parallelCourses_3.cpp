/*

    LEETCODE 2050

You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.
*/

#include<bits/stdc++.h>

using namespace std ;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> indeg(n,0);
    vector<vector<int>> adjList(n);
    for(auto i : relations){
        indeg[i[1]-1]++;
        adjList[i[0]-1].push_back(i[1]-1); // because later i want to see the times of previous courses for a course
    }
    queue<int>q ;
    vector<int> min_time(n , -1e9);
    for(int i = 0 ; i < n ; i++){
        if(indeg[i] == 0){
            q.push(i);
            min_time[i] = time[i];
        }
    }


    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : adjList[curr]){
            min_time[i] = max(min_time[i] , min_time[curr]+time[i]);
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }
    int ans = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        cout<<min_time[i]<<" "<<i+1<<endl ;
        ans = max(ans , min_time[i]);
    }

    return ans ;
}