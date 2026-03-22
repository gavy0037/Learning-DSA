/*
Given k sorted arrays merge them into one sorted array in time less than nlogn where n is the total number of elements
*/

#include<iostream>
#include <vector>
#include<queue>

using namespace std ;


class info{
    public:
        int val ;
        int array_index ;
        int ptr ;

        info(int val ,int array_index , int ptr){
            this->val = val ;
            this->array_index = array_index ;
            this->ptr = ptr ;
        }
};

class cmp{
    public:
        bool operator()(info *a , info *b){
            return a->val > b->val ;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>& nums, int k)
{
    priority_queue< info* , vector<info*> , cmp > pq ; // means heap to store element , vector index
    
    // make k info pointers
    for(int i = 0 ; i < k ; i++){
        if(nums[i].size() == 0) continue ;
        info *newinfo = new info(nums[i][0] , i , 0);
        pq.push(newinfo);
    }

    vector<int>ans ;
    while(!pq.empty()){
        info* curr = pq.top() ;
        pq.pop();

        ans.push_back(curr->val);
        int idx = curr->array_index ;
        int new_ptr = curr->ptr+1 ;
        if(new_ptr == nums[idx].size()) continue ;

        info *newinfo = new info(nums[idx][new_ptr] , idx , new_ptr);
        pq.push(newinfo);

    }
    return ans ;
}


// MY SOLUTION 

class cmp{
    public :
        bool operator()(pair<int , int > &a , pair<int , int> &b){
            return a.first > b.first ;
        }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size() , m = mat[0].size();
        
        priority_queue<pair<int , int> , vector<pair<int , int >> , cmp >pq ;
        vector<int>pointer(n , 0);
        for(int i = 0 ; i < n;  i++) pq.push({mat[i][0] , i});
        vector<int>ans ;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            ans.push_back(curr.first);
            int idx = curr.second ;
            if(pointer[idx] < m-1){
                pointer[idx]++;
                pq.push({mat[idx][pointer[idx]], idx});
            }
        }
        return ans ;
    }
};