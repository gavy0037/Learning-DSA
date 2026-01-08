/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
*/

#include<queue>

using namespace std ;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int , vector<int> , greater<int>>pq ;
    for(int i = 0 ;i < arr.size() ; i++){
        pq.push(arr[i]);
    }
    int ans =0 ;
    while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if(pq.empty()) break ;// means now there is only one element that is the answer
        int second = pq.top();
        pq.pop();
        ans+=(first+second);
        
        pq.push(first+second);
    }
    return ans ;
}