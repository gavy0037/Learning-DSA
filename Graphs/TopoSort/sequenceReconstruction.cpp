/*
================================================================================
Problem Statement: Sequence Reconstruction (LeetCode 444)

Let `nums` be a sequence of length `n` that is a permutation of the integers in 
the range [1, n]. 

Let `S = {s_1, s_2, ..., s_k}` be a set of sequences, where each sequence `s_i` 
in `S` is a subsequence of `nums`.

Determine if `nums` is the unique shortest supersequence of the set `S`. 
Return `true` if it is, and `false` otherwise.
================================================================================
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        
        // Step 1: Initialize your Graph (adjList) and In-Degree array here
        vector<vector<int>> adjList(n+1);// n=1 because 1 to n
        vector<int> indeg(n+1,0);
        // Step 2: Build the Graph from the `sequences`
        for(auto vec : sequences){
            for(int i = 1 ; i < vec.size() ; i++){
                adjList[vec[i-1]].push_back(vec[i]);

                indeg[vec[i]]++;
            }
        }
        // Step 3: Setup the Queue with all nodes having an in-degree of 0

        queue<int>q ;
        for(int i = 1; i <= n ;i++) if(indeg[i] == 0) q.push(i);
        // Step 4: Perform Kahn's Algorithm
        vector<int>topoSort ;
        while(!q.empty()){
            if(q.size() > 1) return false ;
            int node = q.front();
            topoSort.push_back(node);
            q.pop();

            for(auto i : adjList[node]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        // Hint: Remember the "Queue Size Rule" for uniqueness!
        
        return topoSort == nums ;
    }
};

// Main function for local testing
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Example Test Case
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sequences = {{1, 2}, {1, 3}};

    bool result = sol.sequenceReconstruction(nums, sequences);
    
    if (result) {
        cout << "True: The sequence is uniquely reconstructable." << "\n";
    } else {
        cout << "False: The sequence is NOT uniquely reconstructable." << "\n";
    }

    return 0;
}