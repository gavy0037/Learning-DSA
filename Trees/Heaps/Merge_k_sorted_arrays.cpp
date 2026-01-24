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
