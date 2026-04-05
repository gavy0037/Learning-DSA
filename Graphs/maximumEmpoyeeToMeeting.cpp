/*
A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.
*/

#include<bits/stdc++.h>

using namespace std; 

int maximumInvitations(vector<int>& fav) {
    int n = fav.size();
    // make a directed graph from i to fav[i]
    // we will only make a indegree array as that is what i need
    vector<int>indegree(n , 0 );
    for(int i = 0 ; i  < fav.size() ; i++){
        indegree[fav[i]]++;
    }

    queue<int>q ;
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0) q.push(i);
    }

    // kahn's alog takes out all nodes that are not in a cycle , we will use them to measure the length of straight chains

    vector<int>depth(n , 1); // this is will keep a track of the max length of straight chain starting from a employee
    // by default every single node is a chain length of 1

    while(!q.empty()){
        int node = q.front();
        q.pop();

        int nextPerson = fav[node];
        depth[nextPerson] = max(depth[nextPerson] , 1+depth[node]);

        indegree[nextPerson]--;
        if(indegree[nextPerson] == 0) q.push(nextPerson);
    }
    // now which ever node's indegree is still not 0 , it's part of cycle

    // we can make a cycle of employee sit on the table , so we will see the max-length cycle
    // if length of cycle is 2 , then they can from a part of a straight chain at their other end so a special case for them
    int cycleArrangement = -1 , chainArrangement = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] != 0){
            int stNode = i , length = 1 ;
            indegree[stNode] = 0 ;
            int nextNode = fav[stNode];

            while(nextNode != stNode){
                indegree[nextNode] = 0 ;
                length++;
                nextNode = fav[nextNode];
            }

            cycleArrangement = max(cycleArrangement , length);

            if(length == 2){
                chainArrangement += depth[stNode]+depth[fav[stNode]];
                // if cycle of 2 , then the nodes will be just st node and fav of stnode , also these will be added continuously as when a chain of one 2length cycle is done , then at end those people don't have anychoice of fav , so i can make other chain arrangements sit there. Also one length2 cycle can't have another one in it's chain as there is only one fav person of each person.
            }
        }
    }

    return max(cycleArrangement , chainArrangement);
}