/*
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.
*/

#include<queue>
#include<vector>
 
using namespace std ;

int getKthLargest(vector<int> &arr, int k){
	int n = arr.size();
	priority_queue<int, vector<int> , greater<int>>pq ;
	for(int i = 0 ;i < n ; i++){
		int sum = 0 ;
		for(int j = i ; j < n ; j++){
			sum+=arr[j];
			if(pq.size() < k) pq.push(sum);
			else if(pq.top() < sum){
				pq.pop();
				pq.push(sum);
			}
		}
	}

	return pq.top();
}